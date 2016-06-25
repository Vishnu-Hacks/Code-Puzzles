/*
The edit distance between two strings is the minimum number of insertions, deletions, and mismatches in
an alignment of two strings.

Task.
----
The goal of this problem is to implement the algorithm for computing the edit distance between two
strings.
*/

// -------------------------------------------------//

// A link to stanford Notes on edit distance: 
// https://web.stanford.edu/class/cs124/lec/med.pdf

//--------------------------------------------------//

#include<iostream>
#include<string>

long min(long a, long b,long c)
{
	//std::cout << a << " " << b << std::endl;
	long k= (a < b ? a : b);
	return k < c ? k : c;
}

// This recursive approach is inefficent because of over lapping sub problems,exponent time 
long editDist(std::string s1, std::string s2, size_t l1 = 0, size_t l2 = 0) {
	if (l1 >= s1.length() || l2 >= s2.length())
		return l1 >= s1.length() ? (s2.length() - l2) : (s1.length() - l1);
	// s1 or s2 is empty the s1 needs to add/delete remainng chars in s2/s1 , each cost '1'.

	if (s1[l1] == s2[l2])
		return  editDist(s1, s2, l1+1, l2+1);
	else
	{
		return min(1+editDist(s1, s2, l1+1, l2), 1+editDist(s1, s2, l1, l2+1),1+editDist(s1,s2,l1+1,l2+1));
	}
}

long editDist_fast(const std::string s1, const  std::string s2) {

	long** arry = new long*[s1.length() + 1];
	for (long i = 0; i <= s1.length(); ++i)
	{
		arry[i] = new long[s2.length() + 1];
		arry[i][0] = i; // a situation where 's1' has elements 's2'is empty.
							 // in order to attainn s2,the s1 has to delete each cahcraters (+1)
	}

	for (long i = 0; i <= s1.length(); ++i)
	{
		arry[0][i] = i; // a situation where 's1' is empty ands 's2' has elements.
							// in order to attainn s2,the s1 has to insert each cahcraters (+1)
	}
	int del = 0, ins = 0, rep = 0;
	for (long i = 1; i <= s1.length(); ++i)
	{

		for (long j = 1; j <= s2.length(); ++j)
		{


			if (s1[i - 1] == s2[j - 1]) // if characters are same ,nothinh to do;
			{
				arry[i][j] = arry[i - 1][j - 1];

			}
			else
			{
				del = arry[i - 1][j] + 1;// delete char from s1 ,'1' is the cost of deletetion and add this to cost of making s2(0-j) without s1[i] 
				ins = arry[i][j - 1] + 1;// insert the char from s2 and add the remaing cost making s1(0-i) to s2(0-(j-1)),'1' is the cost of insertion 
				rep = arry[i - 1][j - 1] + 1;//'1' is the cost of replacement, add this to the reming cost to make fron s1(0,i-1) to s2(0,j-1);



				arry[i][j] = min(del, ins, rep);// we will save the mininum cost of these three as the cost of making s1(0-l1) to s2(0-l20)

			}
		}

	}
	return arry[s1.length()][s2.length()]; // The will be the cost to make s1 to s2  [s1(0-s1.length) - s2 (0-s2.lenth);
}
int main() {
	std::string str1, str2;
	std::cout << "ENter \n1. For manual entry\n2. Automatic Entry\n : ";
	char ch;
	std::cin >> ch;
	if (ch != '2') {
		std::cin.ignore(); std::cin.clear();
		std::cout << "Enter String 1: ";
		std::getline(std::cin, str1);
		std::cout << "Enter String 2: ";
		std::getline(std::cin, str2);
	}
	else {
		str1 = "SSSVPSQKTYQGSYGFRLGFLHSGTAKSVTCTYSPALNKMFCQLAKTCPQLWVDSTPPPGTRVRAMAIYKQSQHMTEVVRRCPHHERCSDSDGLAPPQHLIRVEGNLRVEYLDDRNTFRHSVVVPYEPPEVGSDCTTIHYNYMCNSSCMGGMNRRPILTIITLEDSSGNLLGRNSFEVRVCACPGRDRRTEEENL";
		str2 = "SCAVPSTDDYAGKYGLQLDFQQNGTAKSVTCTYSPELNKLFCQLAKTCPLLVRVESPPPRGSILRATAVYKKSEHVAEVVKRCPHHERSVEPGEDAAPPSHLMRVEGNLQAYYMEDVNSGRHSVCVPYEGPQVGTECTTVLYNYMCNSSCMGGMNRRPILTIITLETPQGLLLGRRCFEVRVCACPGRDRRTEEDNY";
		std::cout << str1 << std::endl << std::endl << str2 << std::endl;
	}
	std::cout << std::endl << "Minimum Edit Distance (Fast): "; 
	std::cout << editDist_fast(str1, str2) << "\n";
	std::cout << std::endl << "Minimum Edit Distance (slow): ";
	std::cout << editDist(str1, str2) << "\n";
}

