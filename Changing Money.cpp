// Changing Money.cpp : Defines the entry point for the console application.
/*
The goal in this problem is to find the minimum number of coins needed to change the given amount
of money using coins with denominations 1, 5, and 10.
*/

#include <iostream>

int getCoins(int amount) {

	return amount % 10;
}

int main()
{
	int amt = 0;
	while (std::cin.good())
	{
		std::cout << "How Much Amount : "; std::cin >> amt;
		std::cout << "Minimum Number of Coins with denominations 1, 5, and 10 = " << getCoins(amt) << "\n\n";
	}
    return 0;
}

