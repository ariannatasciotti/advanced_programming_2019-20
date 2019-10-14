#include <iostream>
#include <cmath>
using namespace std;


int main() {
size_t n;
cout << "Please, enter the maximum value of the prime number up to which you want to reach: " ;
cin >> n;
bool primes[n];  
                                                //initialization
	for (int i=0; i<=n; i++) {
		primes[i]= true;
}

for (int i=2; i<=sqrt(n); i++) {
		if (primes[i] == true) {
			for(int j = i*i; j<=n; j+=i) {
				primes[j] = false;
			}
		}
	}
	
for (int i=2; i<=n; i++) {
		if (primes[i]) {
			cout << i << " "<< endl;;
		}
	}

return 0;
}