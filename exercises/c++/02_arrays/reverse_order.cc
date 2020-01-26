#include <iostream>
using namespace std;

template <typename T>
T* size(size_t n) {
	int* arry{new int[n]};
	for (size_t i{0}; i<n; ++i) {
		cin >> arry[i]; }
	return &arry[0];  //return arry is the same
}

template<typename S>
void print(S* arry, size_t n) {
	for(size_t i{n}; i > 0; --i){
		cout << " " << endl;
		cout << arry[i-1]<<endl;}
		
  //while(n)
  	//cout << arry[--n] << " " ;
  	
  //	while(n--)
  //	cout << arry[n];
}

int main() {
cout<<"Please, enter the lenght of the array: "<<endl; 
size_t n;
cin>>n;
cout<<"Please, enter the elements of the array: "<<endl; 
int* pt = size<int>(n);
print<int>(pt,n);
delete[] pt;
return 0;
}
