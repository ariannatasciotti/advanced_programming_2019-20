#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
cout << "Please, enter the maximum value of the prime number up to which you want to reach: " ;
int n;
cin >> n;
vector<int> primes;
vector<bool> vec (n,true);        //vector of booleans
	for (int i=2; i<=sqrt(n); i++) {
			for(int j = i*i; j<=n; j+=i) {
				vec[j] = false;
			}
		}
for (auto i = 2; i <= n; ++i) {
	if(vec[i]) {
		cout << i << " " << endl;	
}
}
return 0;
}