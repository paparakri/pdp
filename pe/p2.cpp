#include<stdio.h>

int main() {
	
	int a = 1, b = 1, c = 2, sum = 2;
	
	printf("%d\n", 1);
	printf("%d\n", 1);
	for(int i=3;c<=4000000;i++) {
		if(c%2==0) sum += c;
		printf("%d\n", c);
		a = b;
		b = c;
		c = a + b;
	}
	printf("Sum: %d\n", sum);
	
	return 0;
}
