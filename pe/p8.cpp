#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int length = 1000;
	int span = 13;
	char digits[10000];
	scanf("%s", digits);
	
	long long best = 0;
	
	
	
	
	for (int i = 0; i < length - span; i++ ) {
		long long p = 1; 
		for (int j = 0; j< span; j++ ) {
			p *= digits[i+j] - '0';
		}
		
		if(p> best) best = p;
		
	}
	
	printf("%lld\n", best);
    return 0;
}
