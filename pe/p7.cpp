#include<stdio.h>

int isprime(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}


int main() {
	int i, cnt = 0;
	for(i=2;cnt<10001;i++) {
		if(isprime(i)) 
			cnt++;
	}
	printf("%d\n", i-1);
	
	
	return 0;
}

