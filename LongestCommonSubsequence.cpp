#include <iostream>
#include<string>

using namespace std;
long max(long a, long b)
{
	return b > a ? b : a;
}
// slow due to overlapping subproblems- Use dynamic programming instead
long LCSeq(string s1, string s2,int len1,int len2)
{
	if (len1 <= 0 || len2 <= 0)
		return 0;

	if (s1.at(len1) == s2.at(len2))
	{
		return 1 + LCSeq(s1, s2, len1 - 1, len2 - 1);
	}
	else
		return max(LCSeq(s1, s2, len1 - 1, len2), LCSeq(s1, s2, len1, len2 - 1));
}

long LCSeqFast(string s1, string s2) {
	
	long**arr = new long*[s1.length() + 1];
	for (long i = 0; i <= s1.length(); ++i)
	{
		arr[i] = new long[s2.length() + 1];
		arr[i][0] = 0;
	}
	for (long i = 0; i <= s2.length(); ++i)
	{
		arr[0][i] = 0;
	}

	for (long i = 1; i <= s1.length(); ++i)
	{
		long index1 = i - 1;
		for (long j = 1; j <= s2.length(); ++j)
		{
			long index2 = j - 1;
			if (s1.at(index1) == s2.at(index2))
			{
				arr[i][j] = 1 + arr[i - 1][j - 1];
			}
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	return arr[s1.length()][s2.length()];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	std::cout << "Largest Common Sequence : "; cout << LCSeqFast(s1, s2) << endl;
}
