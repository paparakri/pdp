#include <stdio.h>
using namespace std;

int coins[]={1,2,5,10,20,100,200};

int solve(int x, int coin){
	if(x<0) return 0;
	if(x==0) return 1;
	if(coin==1) return 1;
	return solve(x,coin-1)+solve(x-coins[coin], coin);
}

int main(){
	int result = solve(200,8);
	printf("%d", result);
	return 0;
}
