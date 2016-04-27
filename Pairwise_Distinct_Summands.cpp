#include <iostream>
typedef long long Long;
/*
Task
====
The goal of this problem is to represent a given positive integer n as a sum of as many pairwise
distinct positive integers as possible. That is, to find the maximum k such that n can be written as
a1 + a2 + · · · + ak where a1, . . . , ak are positive integers and ai 6= aj for all 1 ≤ i < j ≤ k.

Input Format===========The input consists of a single integer n
*/

// Takes an Integer as a  parameter
int findSumPairs(Long num) {

	if (num <= 2) {
		std::cout << "No Distinct pairwise SUm!\n"  << std::endl;
		return 0;
	}
	int i = 1;
	int count = 0;
	std::cout << "1";     // Taking '1' as the first sum pair
	num -= 1;             // Reducing 1 from num.
	while (num != 0) { 
		++i;                          
		if (i * 2 < num) {                 // i is a sum pair if i*2 is less than the remaining integer.
			std::cout << " + " << i;       // figured-out by analysing different sum pairs.
			num -= i;
			++count;
		}
		else {                                 
			std::cout << " + " << num << "\n"; 
			num -= num;
			++count;
			break;
		}
	}
	std::cout <<"Number Of Distinct Count : "<<count<<"\n"<< std::endl;
	return 0;
}

int main() {
	Long num = 0;
	while (std::cin.good()) {
		std::cout << "Enter The NUmber : "; std::cin >> num;
		findSumPairs(num);
		
	}
	return 0;
}