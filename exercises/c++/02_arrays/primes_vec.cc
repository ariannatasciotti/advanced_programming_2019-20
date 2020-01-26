#include <iostream>
#include <vector>
using namespace std;

int primenumber(int n) {
bool isprime = true;
for (int i=2; i<=n/2;i++) {
	if(n%i == 0){  
		isprime = false;
		break;
	}
}
return isprime;
}


int main() { 
vector<int> primes; 
size_t n{100}; 
bool isprime;
for(int i=2; i<n; i++) {
	isprime = primenumber(i);
	if(isprime==true) {
		primes.push_back(i);
	}
}
for (auto i = primes.begin(); i < primes.end(); ++i) {
	cout << *i << " " << endl;	
}
return 0;
}


