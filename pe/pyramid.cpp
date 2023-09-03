#include <stdio.h>
#include <algorithm>
using namespace std;


int p[1010][1010];

int d(int i, int j) {
	
	if(i==14) return p[i][j];
	
	return max( d(i+1,j) ,  d(i+1,j+1) ) + p[i][j];
	
}

int main(){
	
	freopen("pyramid.in", "r", stdin);
	
	for(int i=0; i<15; i++){
		for(int j=0; j<i+1; j++){
			scanf("%d", &p[i][j]);
		}
	}
	
	printf("%d\n", d(0,0) );
	
	return 0;
}
