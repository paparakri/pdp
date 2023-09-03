#include <stdio.h>
using namespace std;

int isDivisible(int num){
	for(int i=1; i<=20; i++){
		if(num%i != 0) return 0;
	}
	return 1;
}

int main(){
	
	for(int i=20; ; i++){
		if(isDivisible(i) == 1){
			printf("%d", i);
			break;
		}
	}
	
	return 0;
}
