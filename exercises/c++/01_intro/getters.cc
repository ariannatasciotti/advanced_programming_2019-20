#include <iostream>
#include <string>

void get_int() {
  int a; 
  std::cout << "Enter an integer: ";
  while(!(std::cin >> a)){
    std::cin.clear(); 
    std::cin.ignore();     
  }
  std::cout << "You entered: "<< a << std::endl; 
}

void get_double(){
  double a;
    std::cout << "Enter a double: ";
  while(!(std::cin >> a)) {
    std::cin.clear();
    std::cin.ignore();  
  }
  std::cout << "You entered: "<< a << std::endl;; 
}

int main() {
	
	std::cout << "Type 'int' to read an integer or type 'double' to read a double: ";
	std::string a;
	std::cin >> a;
    
    if(a == "int") {
    	get_int();
 	}
 	else if(a == "double") {
 		get_double();
 	}
  return 0;
}

