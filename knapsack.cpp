/*
This problem is about implementing an algorithm for the knapsack without repetitions problem.

Task.
----
In this problem, you are given a set of bars of gold and your goal is to take as much gold as possible
into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence
you cannot take a fraction of a bar).

*/

#include <iostream>
#define Long unsigned long long

Long maxWeight(Long max,Long* wgts,Long num )
{
	// The memory table that stores the maximum weight for a given num from a wgt(0 to max)
	Long** arry = new Long*[num];
	for (Long i = 0; i < num; ++i)
	{
		arry[i] = new Long[max+1];
		arry[i][0] = 0;// if wgt is zero then max from given num quantitis is zero
		
	}
	for (Long i = 0; i  <= max; ++i)
		arry[0][i] = 0; //qunatity at 0th postion is assigned 0 for algorithm.the 1st quantity starts at postion 1.

	// storing the max weight possible from given i number elements if max weight is j(0-max)
	// the value stores in arry[i=3,j=5] is the maximum weight possible to carry using 3 elements and bag max weight is 5
	// the value stored in the arry[i=num,j=max] will be the max weight from num valuees and our result
	for (Long i = 1; i < num; ++i)
	{
		for (Long j = 1; j <= max; ++j)
		{
			// if the possible max weight using i number of quantites is greater than weight 
			// of the current item, then we can take that item and remaining weight (j-wgts[i] ) can be filled 
			// by taking the max weight using elements other than current item(i-1)
			// because items cannot be repeated.
			if (j >= wgts[i])
			{
				arry[i][j] = wgts[i] + arry[i-1][j - wgts[i]];
			}
			else
			{
				// if the max possible weight is less than the weight of current item,
				// we can't take the  current item , so we select the max weight from
				// items other than the current one(i-1)
				arry[i][j] = arry[i - 1][j];
			}
			
		}
	}
	return arry[num-1][max];
}
int main() {

	std::cout << "ENter The Max Weight of the Knascpack  : ";
	Long max = 0;
	std::cin >> max;

	std::cout << "Enter the number of items  :  ";
	Long num = 0;
	std::cin >> num;

	Long* wgt = new Long[num+1];
	std::cout << "Enter the weight\n";
	if (num < 5)
	{
		wgt[0] = 0;
		Long i = 1;
		while (i <= num) {
			std::cin >> wgt[i];
			std::cin.ignore(1);
			++i;
		}
	}
	else
	{
		Long i = 0;
		srand(num);
		while (i <= num)
		{
			wgt[i++] = rand() % 10;
			std::cout << wgt[i - 1] << " ";
		}

	}
	std::cout << "\nMax Weight : "; std::cout << maxWeight(max, wgt, num+1) << std::endl;
}
