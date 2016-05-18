/*
Problem Introduction
In this problem, you will implement the binary search algorithm that allows searching very eficiently (even huge)
lists provided that the list is sorted.

Input Format.
The 1st line of the input contains an integer n and a sequence a0 < a1 < : : : < a(n-1) of n pairwise distinct 
positive integers in increasing order. The next line contains an integer k and k positive integers b0; b1; : : : ; b(k-1).

Output Format. 
For all i from 0 to k-1, output an index 0  j  n-1 such that aj = bi or -1 if there is no such index.
*/
#include <iostream>
#define Long  long long
Long* MergeSort(Long* main, Long num);


Long BinarySearch(Long*arr, Long key, Long from,Long to) {
	if (from > to)
		return -1;
	Long count = -1;
	Long mid = (from + to) / 2;

	if (key == arr[mid]) {

		return mid;
	}
	else if (key < arr[mid])
		count = BinarySearch(arr, key, from, mid - 1);
	else
		count = BinarySearch(arr, key, mid + 1, to);

	return count;
}

int main() {
	std::cout << "Output = Element|Index, Index= -1 => element not found!\n\n";
	Long num1 = 0, num2 = 0;
	std::cout << "Enter The Number Of Elements in Main Array : ";
	std::cin >> num1;
	Long *main = new Long[num1];
	srand(num1 + 100);
	for (Long i = 0; i < num1; ++i) {
		main[i] =  rand() % 100;
	}

	MergeSort(main, num1);

	std::cout << "Enter The Number Of Elements in Search List Array : ";
	std::cin >> num2;
	Long *search = new Long[num2];
	srand(num2 + 98);
	for (Long i = 0; i < num2; ++i) {
		search[i] = rand() % 100;
	}
	std::cout << "\n\n";

	// Taking each element from search array and searching in main array
	for (Long i = 0; i < num2; ++i) {
		std::cout << search[i] << "|";
		std::cout << BinarySearch(main, search[i], 0, num1) << "  ";
		if ((i+1) % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "Output = Element|Index, Index= -1 => element not found!\n\n";
	return 0;
}


Long* Merge(Long*arr1, Long*arr2, Long* arr, Long num);

Long* MergeSort(Long *arr, Long num) {
	if (num < 2) {
		return arr;
	}
	Long mid = num / 2;
	Long* half1 = new Long[mid];
	Long *half2 = new Long[num - mid];

	half1 = MergeSort(arr, mid);
	half2 = MergeSort(&arr[mid], num - mid);

	return Merge(half1, half2, arr, num);
}


Long* Merge(Long*arr1, Long*arr2, Long* arr, Long num) {

	Long mid = num / 2;
	Long h1 = 0, h2 = 0;
	Long* temp = new Long[num];
	Long i = 0;
	while (h1 < mid && h2 < (num - mid)) {
		if (arr1[h1] < arr2[h2]) {
			temp[i] = arr1[h1];
			++h1;
		}
		else {
			temp[i] = arr2[h2];
			++h2;
		}
		++i;
	}
	while (h1 < mid) {
		temp[i] = arr1[h1];
		++i; ++h1;
	}
	while (h2 <  (num - mid)) {
		temp[i] = arr2[h2];
		++h2; ++i;
	}
	for (Long i = 0; i < num; ++i) {
		arr[i] = temp[i];
	}
	return arr;
}
