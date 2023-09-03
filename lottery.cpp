#include <stdio.h>
#include <algorithm>
using namespace std;
int K, N, Q;

char X[110];
char Y[110];

long long price[120];

struct node {
	char c;
	int cnt;
	node* child[10];
	node(char x) {
		cnt = 0;
		c = x;
		for(int i=0;i<10;i++) child[i] = nullptr;
	}
	
	void insert(int m) {
		cnt++;
		if(m==K) return;
		int i = X[m] - '0';
		if( child[i] == nullptr ) child[i] = new node(X[m]);
		child[i]->insert(m+1);		
	}
	pair<int,int> find(int m) { 		
		pair<int, int> ans = {0,0};
		if(Y[m] != '\0') {
			int i = Y[m] - '0'; 
			if( child[i] != nullptr ) {
				ans = child[i]->find(m+1);
			}
		}
			
		int count = (m==0)?ans.first:cnt;
		int sum =  (ans.second + (long long)(cnt - ans.first)*price[m] ) % 1000000007;
			
		return {count, sum};
		
	}
		
	
};

int main() {
	
	
	freopen("lottery.in","r", stdin);
	freopen("lottery.out","w", stdout);
	
	scanf("%d %d %d", &K, &N, &Q);
	
	for(int i=0, p=1;i<=K;i++, p=((long long)p*2) % 1000000007 ) {
		price[i] = (p - 1) % 1000000007;
	}
	
	node* T = new node('$');
	for(int i=0;i<N;i++) {
		scanf("%s\n", X);
		reverse(X, X+K);
		T->insert(0);
	}
	
	for(int i=0;i<Q;i++) {
		scanf("%s\n", Y);
		reverse(Y, Y+K);
		pair<int, int> ans = T->find(0);
		printf("%d %d\n", ans.first, ans.second);		
	}	
}
	
