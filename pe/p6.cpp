#include <stdio.h>
using namespace std;

int main(){
	long long sumofsquares = 0;
	long long squareofsum = 0;

	for(int i=1; i<101; i++){
		sumofsquares += i*i;
		squareofsum += i;
	}
	
	squareofsum *= squareofsum;
	long long result = squareofsum - sumofsquares;
	
	printf("%ld", result);
	
	return 0;
}
