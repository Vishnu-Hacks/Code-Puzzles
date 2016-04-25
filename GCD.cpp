#include <iostream>
typedef long long Long;
class GCD {
public:
	GCD() {}
	// General algorithm
	 Long findGcd(Long num1, Long num2) {
		 Long high = num1 > num2 ? num1 : num2;
		 Long low = num1 < num2 ? num1 : num2;
		 int k = 0;
		 if (low == 0) {
			 std::cout << "Invalid input\n\n"; exit(0);
		 }
		 if (high%low == 0) {
			 return low;
		 }
		 for (Long i = (Long)low / 2; i != 1; --i) {
			 ++k;
			 if (high%i == 0)
				 if (low%i == 0) {
					 std::cout <<"("<< k << " steps)  => ";
					 return i;
				 }
		 }
		 std::cout << "("<<k << " steps)  => ";
		 return 1;
	}
	//Better Algorithm - Eucledian Algorithm 
	 /*
	
	 The Euclidean algorithm is based on the principle that the greatest common divisor 
	 of two numbers does not change if the larger number is replaced by its difference
	 with the smaller number.

	 gcd(high,low)==gcd(high-low,low)
	  
	This will effectively reduces the number of steps in calculating the algorithm.

	Probelm : 1. IF the different between the hihghest and the lowest are larger,
	           then more subtraction steps are required.
			   ex:  gcd(2,100) -> will have 50 steps
			  2. If the Numbers are too close then more subtraction steps are required.
			   ex: gcd(99,100) , in the second step it becomes > gcd(99,1)=>problem(1)

	
	
	 */
	Long findGcd2(Long num1, Long num2) {
		Long high = num1 > num2 ? num1 : num2;
		Long low = num1 < num2 ? num1 : num2;
		int i = 0;
		while (high != low) {
			++i;
			high -= low;
			if (high < low) {
				num1 = high;
				high = low;
				low = num1;
			}
		}
		std::cout <<"("<< i << " steps)  => ";
		return low;
	}
	//Best Algorithm - Eucledian Algorithm(Gabrieal Lame Method)
	/*
	The version of the Euclidean algorithm described above (and by Euclid)
	can take many subtraction steps to find the GCD when one of the given numbers 
	is much bigger than the other. A more efficient version of the algorithm shortcuts
	these steps, instead replacing the larger of the two numbers by its remainder when 
	divided by the smaller of the two. With this improvement, the algorithm never 
	requires more steps than five times the number of digits (base 10) of the smaller integer.
	This was proven by Gabriel Lamé in 1844, and marks the beginning of computational
	complexity theory. Additional methods for improving the algorithm's efficiency were 
	developed in the 20th century.
	*/
	Long findGcd3(Long num1, Long num2) {
		Long high = num1 > num2 ? num1 : num2;
		Long low = num1 < num2 ? num1 : num2;
		int i = 0;
		while (low!=0) {
			++i;
			high %= low; // replacing the larger of the two numbers by its remainder when 
	                     // divided by the smaller of the two
			if (high < low) {
				num1 = high;
				high = low;
				low = num1;
			}
		}
		std::cout << "(" << i << " steps)  => ";
		return high;
	}
};

int main() {
	GCD gcd;
	while (std::cin.good()) {
		Long a, b;
		std::cout << "Enter The 1st Number : ";
		std::cin >> a;
		std::cout << "Enter The 2nd Number : ";
		std::cin >> b;
		std::cout << "(fast)best Algorithm  : "; std::cout << gcd.findGcd3(a, b) << "\n";
		std::cout << "(slow)Good Algorithm  : "; std::cout << gcd.findGcd(a, b) << "\n";
		std::cout << "(slow)Better Algorithm: "; std::cout << gcd.findGcd2(a, b) << "\n\n";
		
	}
	return 0;
}