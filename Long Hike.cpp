#include <iostream>
#include<Random>
# define WEIGHT 10 // Maximum weight of the bag
void sort(void*a1, void*a2,int i);
// This Funtion takes calories and quantity parallel arrays and 
// number of items in stock.
double getMaxValue(double *calories, double *quantity, int num) {

      // current weight of the bag 
	double wgt= 0.0;
	  // current calorie
	double cal = 0.0;
	int i = 0;
	std::cout << std::endl;
	while (i != num) {
		if ((wgt+quantity[i]) <= WEIGHT) {
			
			cal += calories[i];
			wgt += quantity[i];
			std::cout << quantity[i] << " kg From Item #" << i + 1 << " : " << calories[i] << " Calories\n";
		}
		else {
			double extra = WEIGHT - wgt;
			std::cout << extra << " kg From Item #" << i + 1;
			wgt += extra;
			extra = ( calories[i]/quantity[i] )*extra;
			cal += extra;
			std::cout << " : " << extra<< " Calories\n";
			return cal;
		}
		++i;
	}

	return cal;
}

int main() {

	
	int num = 0; // number of items in stock for hiking"
	std::cout << "Number Items For Hikings : ";
	std::cin >> num;
		//Two parallel arrays that stores the calories and quantity.
		double *calories = new double[num];
		double * quantity = new double[num];

		int max_wgt = WEIGHT;
		// giving random values to quantity and calories
		srand(num);
		for (int i = 0; i < num; ++i) {
			calories[i] = (rand() % 10) + 1;
			quantity[i] = (rand() % 10) + 1;
		
		}
		sort(calories, quantity, num); // sorts the arrays in descending order

		for (int i = 0; i < num; ++i) {

			std::cout << "Item #" << 1 + i << ": Calories >  " << calories[i] << ", Quantity >  " << quantity[i] << std::endl;
		}

		std::cout << "Max Calories Values Possible For Hiking : " << getMaxValue(calories, quantity, num) << "\n\n";
	
	return  0;
}


void sort(void*a1, void*a2,int i) {
	double *cal = (double*)a1;
	double *qnt = (double*)a2;
	double temp = 0.0;
	double ratio1, ratio2;
	for (int k = 0; k < i-1; ++k) {
		ratio1 = cal[k] / qnt[k];
		for (int m = k + 1; m < i; ++m) {
			ratio2 = cal[m] / qnt[m];
			if (ratio1 < ratio2) {
				temp = cal[m];
				cal[m] = cal[k];
				cal[k] = temp;

				temp = qnt[m];
				qnt[m] = qnt[k];
				qnt[k] = temp;
			}
		}
	}
	
}