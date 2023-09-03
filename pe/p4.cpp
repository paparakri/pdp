#include<stdio.h>

int ispal(int x) {
	
	int mx=0, mk = x;
	
	while(x>0) {
		mx*=10;
		mx+=x%10;
		x/=10;
	}
	
	
	
	return mx==mk;
}


int main() {
	
	
	int max = 0;
	for(int i=100;i<=999;i++) {
		for(int j=100;j<=999;j++) {
			//printf("%d %d\n", i,j);
			if(ispal(i*j)) {
				max = (i*j>max)?i*j:max;
				printf("%d\n", max);
			}	
			
		}		
	}
	printf("%d\n", max);
	
	
	return 0;
}


