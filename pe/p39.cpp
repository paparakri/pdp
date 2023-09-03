#include <stdio.h>
#include <algorithm>
using namespace std;

int solutions[1000];

int main(){
	
	for(int a=0; a<1000; a++)
		for(int b=0; b<1000; b++)
			for(int c=0; c<1000; c++){
				if(a+b+c>1000) break;
				if(a*a==b*b+c*c) solutions[a+b+c]++;
			}
				
				
	int max = 0;
	int maxindex = 0;
	for(int i=0; i<1000; i++){
		if(solutions[i]>max){
			max=solutions[i];
			maxindex=i;
		}
	}
	
	printf("%d", maxindex);
	
	return 0;
}
