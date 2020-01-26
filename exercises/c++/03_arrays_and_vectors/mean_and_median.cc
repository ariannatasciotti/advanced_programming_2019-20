#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main() {
	std::cout << "Enter the input file name: ";
	std::string file;
	std::cin >> file;
	std::ifstream ist{file};
	std::vector<double> temps;
	double temperature;
	double mean{0};
	while(ist >> temperature) {
		temps.push_back(temperature);
	}
	for(auto i=0; i<temps.size();i++) {
		mean += temps[i];
	}
	std::cout << "Mean of the temperatures: " << mean/temps.size() << std::endl;
	
	std::sort(temps.begin(),temps.end());
	if(temps.size()%2 != 0) {
		double median{temps[(temps.size()-1)/2]};
		std::cout << "Median of the temperatures: " << median << std::endl;
	} else {
		double median{(temps[temps.size()/2]+temps[temps.size()/2-1])/2};
		std::cout <<"Median of the temperatures: " << median << std::endl;
	}
	
	
	return 0;
}
