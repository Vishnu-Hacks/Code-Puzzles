/*
Task
_____
The goal is, given two sequences a1, a2, . . . , an and b1, b2, . . . , bn, find a permutation π of the second
sequence such that the dot product of a1, a2, . . . , an and bπ1, bπ2, . . . , bπn is minimum.

Input Format.
____________

The first line contains an integer n, the second one contains a sequence of integers
a1, a2, . . . , an, the third one contains a sequence of integers b1, b2, . . . , bn.

Output Format
_____________

Output the minimum possible dot product
*/


#include <iostream>

long Min_Dot_Product(const int *arr1, int *arr2, int num) {
	long dot=0;
	int *arr3 = new int[num]; // sorted arr1 in ascending order
	int *arr4 = new int[num]; // sorted arr2 in descendnig order
	int *final = new int[num]; // final arr2 to find dot prduct with arr1
	int temp;
	for (int i = 0; i < num; ++i) {
		arr3[i] = arr1[i];
		arr4[i] = arr2[i];
		final[i] = -1;
	}

	for (int i = 0; i < num - 1; ++i) {
		for (int k = i + 1; k < num; ++k) {
			if (arr3[i] > arr3[k]) {
				temp = arr3[k];
				arr3[k] = arr3[i];
				arr3[i] = temp;
			}
		}
	}



	for (int i = 0; i < num - 1; ++i) {
		for (int k = i + 1; k < num; ++k) {
			if (arr4[i] < arr4[k]) {
				temp = arr4[k];
				arr4[k] = arr4[i];
				arr4[i] = temp;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < num; ++i) {
		
		while (true)
		{
			if (arr3[i] == arr1[j])
				if (final[j] == -1)
					break;
			++j;
		}

		final[j] = arr4[i];
			dot += (final[j])*arr1[j];
		j = 0;
	}

	
	return dot;
}

int main() {
	int length = 0;
	std::cout << "Enter The Length of the Array : "; std::cin >> length;
	int *a1 = new int[length];
	int *a2 = new int[length];
	
	std::cout << "Array 1\n";
	for (int i = 0; i < length; ++i) {
		std::cin >> a1[i]; 
	}
	std::cout << "\nArray 2\n";
	for (int i = 0; i < length; ++i) {
		std::cin >> a2[i]; 
	}

	std::cout << "\nMinimum Dot Product = "; std::cout << Min_Dot_Product(a1, a2, length) << "\n\n";
	return 0;
}