#include <iostream>

void polyProduct(int a1[], int a2[], int n1, int n2) {
	int n = n1 + n2;
	int*result = new int[n];
	for (int i = 0; i < n; ++i) {
		result[i] = 0;
	}

	for (int i = 0; i < n1; i++) {

		for (int j = 0; j < n2; ++j) {

			result[i + j] += (a1[i]*a2[j]);
			std::cout << result[i + j] << "  ";
		}
	}

	std::cout << "Result : \n";
	for (int i = n-1; i >=0; --i) {
		if (result[i] != 0) {
			std::cout << result[i] << "x^" << i<<" + ";
		}
	}
}

int main() {

	int* ar1;
	int* ar2;
	int num = 0;

	std::cout << "Enter The Number Of Elements in polynomial 1 : ";
	std::cin >> num;
	ar1 = new int[num];
	std::cout << "Enter The Polynomial One :  ";
	int i = 0;
	while (i != num) {
	
		std::cin >> ar1[i];
		++i;
	}
	int num2 = 0;
	std::cout << "Enter The Number Of Elements in polynomial 2 : ";
	std::cin >> num2;
	ar2 = new int[num2];
	std::cout << "Enter The Polynomial One :  ";
	 i = 0;
	while (i != num2) {

		std::cin >> ar2[i];
		++i;
	}
	
	polyProduct(ar1, ar2,num,num2);
	return 0;
}