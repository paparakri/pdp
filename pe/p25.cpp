#include<stdio.h>
#include<string.h>

char a[1010];
char b[1010];
char c[1010];


void plus() {
	int k = 0, s, i;
	
	for(i=0;i<strlen(b);i++) {
		if(i<strlen(a))	
			s = (a[i]-'0') + (b[i]-'0');
		else
			s = (b[i]-'0');	
		if(s + k>=10){
			s-=10;
			c[i] = s + k + '0';
			k=1;
		} else {
			c[i] = s + k + '0';
			k = 0;
		}
		
	}
	if(k==1){		
		c[i] = '1';
	}
}

int main() {
	a[0] = '1';
	b[0] = '1';
	
	
	for(int i=3;;i++) {
		plus();
		if(strlen(c) == 1000) {
			printf("%d\n", i);
			return 0;
		}
		strcpy(a,b);
		strcpy(b,c);
	}
	
	
	return 0;
}



