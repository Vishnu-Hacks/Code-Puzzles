#include <iostream>

void sort(void*arr,int num);
//Parameters are the gas stations array of different gas stations in locations from 
//start - end of journey, number of gas stations,total distance to travel and fuel capcity of car .

// A ________station_1________station_2______....station_n... B

// Returns minimum number of refuels required b/w A - B;
int optimal_refuels(int *stations, int num_stations, int distance,int cap) {

	if (cap >= distance)
		return 0;
	if (num_stations == 0)
	{
		std::cout << "!!!!!!!!!!!!!! Car Stops At : " << cap << " km\n";
		return -1;
	}
	sort(stations, num_stations); 
	int refuels = 0;
	int dist = cap; 

	int i = 0;
	while (dist < distance) {

		while (i < num_stations && stations[i] <= dist) {
			++i;
		}

		if (i != 0) //if not first station
		--i;
		
		//  if the distance of the next gas station is more
		// more than the capcaity of car to cover.
		
			if (stations[i] > dist)
			{

				std::cout << "!!!!!!!!!!!!!! Car Stops At : " << dist << " km\n";
				return refuels;

			}
	std::cout << "----" << stations[i];
	dist = cap + stations[i];
	++refuels;

	stations[i] = distance + 1;
	++i;

	}

	return refuels;
}

// Sorts the gas station in distance order
void sort(void*a,int num) {
	int* arr = (int*)a;
	int temp;
	for (int i = 0; i < num - 1; ++i)
		for (int j = i + 1; j < num; ++j) {
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	
}

int main() {
	int l, num, i = 0,c;
	int *gas;
	while (std::cin.good()) {
		std::cout << "Enter Length of Route : "; std::cin >> l;
		std::cout << "Enter the Fuel Capacity of Car : "; std::cin >> c;
		std::cout << "Enter Number of gas station in the route : "; std::cin >> num;
		i = 0;
		gas = new int[num];
		while (i < num) {
			std::cout << "Distance of gas station *" << i+1 << " from Start Point : "; std::cin >> gas[i];
			++i;
		}
		std::cout << "\nOptimal Refuels : " << optimal_refuels(gas, num, l, c) << "\n\n";
	}
	std::cin.clear();
	std::cin.ignore();
	return 0;
}