#include <stdio.h>
using namespace std;
int T, N;
char A[1000010];


bool check(int s, int e, int j, int skip) {
	
	for(int i=s; i<e; i++, j++) {
		if(A[i] != A[j] && skip) {
			skip--;
			j++;
			continue;
		}
		if(A[i] != A[j]) return false;
	}
	return true;	
}

int main() {
	
	
	freopen("symstr.in","r", stdin);
	freopen("symstr.out","w", stdout);
	
	scanf("%d %d", &T, &N);
	for(int t=0;t<T;t++) {
		
		
		
		
		scanf("%s", A);
		
		
		bool left = check(0, N/2, N/2, 1);
		bool right = check(N/2+1, N, 0, 1);
		bool mid = check(0, N/2, N/2+1, 0);
		
		if(left && right && !mid) printf("1\n");
		else if(left){
			for(int i=0;i<N/2;i++) printf("%c", A[i]);
			 printf("\n");
		} else if(right){
			for(int i=N/2+1;i<N;i++) printf("%c", A[i]);
			 printf("\n");
		} else printf("0\n");
			
		
		
	}

	
}
	
