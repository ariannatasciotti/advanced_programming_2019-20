#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
	std::cout << "Enter a sequence of words, press enter to exit: ";
	std::string line;
	std::vector<std::string> rep;
	std::vector<std::string>carbon;
	while (getline(std::cin, line)) {
		if (line.size() == 0) break; 
			std::istringstream iss(line);
			std::string words;
		if (!(iss >> words)) break;
			rep.push_back(words);
	}
	
	for (int i = 0; i<rep.size(); i++) {
		for (int j = 0; j<i; j++) {
			if (rep[j] == rep[i]) {
				rep.erase(rep.begin() +i);
			}
		}
	}
	
	for (auto i = 0; i<rep.size(); i++) {
		std::cout << rep[i] << std::endl;
	}
	
return 0;
}