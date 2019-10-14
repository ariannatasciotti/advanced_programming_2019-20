#include <iostream>
using namespace std;

int primenumber(int n) {
bool isprime = true;
for (int i=2; i<=n/2;i++) {
	if(n%i == 0){  //check the remainder
		isprime = false;
		break;
	}
}
return isprime;
}


int main() {
size_t n{100};  
int* primes{new int[n]};  //allocate one big array
primes[0] = 2;
bool isprime;
for(int i=2; i<n; i++) {
	isprime = primenumber(i);
	if(isprime==true) {
		primes[i]=i;
		cout << i << " " << endl;
	}
}
delete [] primes;
return 0;
}


