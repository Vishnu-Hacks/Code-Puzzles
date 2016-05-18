// Changing Money.cpp : Defines the entry poLong for the console application.
/*
The goal in this problem is to find the minimum number of coins needed to change the given amount
of money using coins with denominations 1, 5, and 10.
*/

#include <iostream>
typedef unsigned long long Long;

Long getCoins(Long amount) {
	int coins[] = { 10,5,1 };
	Long count = 0;
	for (int coin : coins) {
		while (amount >= coin) {
			++count;
			amount -= coin;
		}
	}
	return count;
}

int main()
{
	Long amt = 0;
	while (std::cin.good())
	{
		std::cout << "How Much Amount : "; std::cin >> amt;
		std::cout << "Minimum Number of Coins with denominations 1, 5, and 10 = " << getCoins(amt) << "\n\n";
	}
	return 0;
}

