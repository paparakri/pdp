#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<long long, int> A;
map<long long,int>::iterator it;
long long f(long long x) {
	
	if(x==1) {
		return 1;
	}
	
	it = A.find(x);
	if (it != A.end())
		return it->second;
	

	if(x%2==0) {
		int k = 1 + f(x / 2);
		A.insert({x, k});
		return k;
	}
	else {
		int k = 1 + f(3*x + 1);
		A.insert({x, k});
		return  k;
	}
	
}


int main() {
	
	long long mx = 0, mxi = 0;
	for(int i=1;i<1000000;i++) {
		int k = f(i);
		
		if(k>mx) {
			mx = k;
			mxi = i;
		}
	}
	
	printf("%lld %lld\n", mxi, mx);
	
	return 0;
}
