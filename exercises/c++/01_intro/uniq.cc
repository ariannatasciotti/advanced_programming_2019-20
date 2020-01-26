#include <iostream>
#include <string>

int main() {

  std::string s1;
  std::string s2;
  int i{1};
  
  std::getline(std::cin,s1);
  
  while(std::getline(std::cin,s2)) { 
    if(s1== s2){
      i ++; 
      } 
      else {
		std::cout << "  " << i << " " << s1 << "\n";
		i = 1;
      }
      s1 = s2;
  }
 
  return 0;
}