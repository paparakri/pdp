#include <stdio.h>
#include <string>
using namespace std;


bool isprime(int x) {
	
	for(int i = 2; i*i <= x ;i++) 
		if(x%i == 0) 
			return false;
	return true;
}

int main()
{
	
	
	long long sum = 0;
	for (int i = 2; i < 2000000; i++ ) {
		if(isprime(i)) {
			sum += i;
		}
		
	}
	
	printf("%lld\n", sum);
    return 0;
}

