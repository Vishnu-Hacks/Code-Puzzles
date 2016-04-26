#include<iostream>
#include<vector>

// This Function the ages array and number of children as argument and returns the 
// optimal number of groups possible:
//based on the condition that : Every children in a group differes by less than 1 year.
int makeGroups(double* ages, const int num) {
	std::vector<int>s1;
	std::vector<int>s2;
	int i = 0, groups = 0;

	while (i < num) {
		
		// '-1' are the places where children are selected in a group
		if (ages[i] != -1) {
		
			s1.push_back(ages[i]);
			s2.push_back(ages[i]);
			int k = i+1;
			while (k < num ) {
				// Selects Children MORE than one year age of the ages[i] 
				if (ages[k] <= ages[i]+1 && ages[k]>=ages[i] && ages[k] != -1) {

					s1.push_back(k);
				}
				// Selects Children LESS  than one year age of the ages[i] 
				else if (ages[k] <= ages[i]  && ages[k] >= ages[i]-1 && ages[k] != -1) {

					s2.push_back(k);
				}
				++k;
			}
			// compares the size of the two groups of chidren and selects the max, group
			if (s1.size()>s2.size()) {
				std::cout << "Group #" << groups + 1<< " : " << s1.size() << std::endl;
				while (s1.size()) {
					ages[s1.back()] = -1;
					s1.pop_back();
				}
				++groups;
				s2.clear();
			}
			else {
				std::cout << "Group #" << groups + 1 << " : " << s2.size() << std::endl;
				while (s2.size()) {
					ages[s2.back()] = -1;
					s2.pop_back();
				}
				++groups;
				s1.clear();
			}
		}
		++i;
	}
	
	return groups;
}

int main() {
	
	double *age = nullptr;
	int num = 0;
	while (true) {
		std::cout << "Enter The NUmber of Children : "; std::cin >> num;
		age = new double[num];
		int i = 0;
		while (i != num) {
			std::cout << "Enter The Age of Children #" << 1+i << " : ";
			std::cin >> age[i++];
		}
		std::cout << "Optimal Number of Groups : \n"; std::cout << makeGroups(age, num) << std::endl<<std::endl;
	}
}