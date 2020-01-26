#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

int main() {

  std::cout << "Please enter a number with its proper unit of measure you want to convert: ";
  string a,b;
  double m, a1;
  getline(cin, a);
  b = a.substr(a.find(" ") +1 );
  stringstream geek(a);    //convert string into float
  geek >> a1;
  
  if(b == "inch") {
  	m = a1*0.0254;
  	cout << a1 << " in are " << m << " m " << endl;
  }
  
  if(b == "°C") {
  	m = a1 + 273.15;
  	cout << a1 << " °C are " << m << " K " << endl;
  }

 
  return 0;
}