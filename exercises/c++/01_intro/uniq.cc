#include <iostream>
#include <string>

int main() {

  std::string s1;
  std::string s2;
  int i{1};
    
  std::getline(std::cin,s2);
  
  std::cout << i << " " << s2 << "\n";
  
  while(std::getline(std::cin,s1)) { 
    if(s1== s2){
      i ++; 
      std::cout << i << " " << s2 << "\n";
      } 
      else {
		std::cout << 1 << " " << s1 << "\n";
      }
  }
 
  return 0;
}