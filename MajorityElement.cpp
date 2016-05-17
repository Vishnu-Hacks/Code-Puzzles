/*
Problem Introduction
===================
An element of a sequence of length n is called a majority element if it appears in the sequence strictly more
than n/2 times.

Task. 
=====
The goal in this code problem is to check whether an input sequence contains a majority element.
Max Time : less than 1 sec.

Input Format.
=============
The 1st line contains an integer n, the next one contains a sequence of n non-negative
integers a0; a1; : : : ; an􀀀1.
*/
#include <iostream>
#define ans 3
typedef  long long Long;
Long* MergeSort(Long* arr, Long num);


// This is an in-effective algorothm, as it takes around
// O(n^2) running time. A better algorithm would be one that
// uses less than quadratic time. Given after this one.
Long getMajority(Long *arr, Long num) {
	Long count = 0;
	for (Long i = 0; i < num; ++i) {
		for (Long j = 0; j < num; ++j) {
			if (arr[i] == arr[j])
				++count;
		}
		if (count >= (num / 2))
			return arr[i];
		count = 0;
	}
	return -1;
}

//Optimized algorithm
//This algorithm sorts the array with O(nlogn) time and
// then finds the majority element in O(n) time.
Long findMajority(Long *arr, Long num) {

	arr = MergeSort(arr, num); // Merge Sort with O(nlogn) time
	 
	Long count = 1, i = 0; 
	Long b4 = 0, element = 0;
	while (i < num-1) {   // O(n) time to find majority
		if (arr[i] == arr[i + 1])
			++count;
		else {
			if (count >= (num / 2))
				return arr[i];
			count = 1;
		}
		++i;
	}
	if (count >= (num / 2))
		return arr[i];

	return -1; // No Majority
}


int main() {
	std::cout << "'Enter The Number Of Elements and the array will be randomly created, '-1' means no majority'\n\n";
	std::cout << "Enter The Number Of Elements : ";
	Long num = 0;
	std::cin >> num;
	Long *arr = new Long[num];
	Long *tmp = new Long[num];
	for (Long i = 0; i < num; ++i) {
		arr[i] = rand() % 5;
		tmp[i] = arr[i];
	}
	std::cout << "Fast Algorithm : Start!\n";
	Long a = findMajority(arr, num);
	std::cout << "Majority Element : " << a << "\n";

	std::cout << "\nSlow Algorithm : Start!\n";
	a = getMajority(tmp, num);
	std::cout << "Majority Element : " << a << "\n";
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





















//.














//