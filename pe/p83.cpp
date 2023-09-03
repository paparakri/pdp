#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define INF 1234567890
using namespace std;

vector< pair<int, int> > G[10000];
set< pair<int, int> > S;

int start[6400];
long long dist[100000];
int vis[100000];
int main(){
	
	int N=6400;
	
	freopen("input.in","r", stdin);
	
	for(int i=0; i<N; i++) {
		scanf("%d,", &start[i]);
	}
	
	
	for(int i=0;i<N;i++) {
		if(i>80) G[i].push_back({start[i-80], i-80});
		G[i].push_back({start[i+80], i+80});
		
		if((i+1)%80!=0){
			G[i].push_back({start[i+1], i+1});
		}
		if((i)%80!=0){
			G[i].push_back({start[i-1], i-1});
		}
	}
	
	for(int i=0;i<=N;i++) dist[i] = INF;
	
	dist[0] = 4445;
	S.insert({dist[0],0});
	
	
	while(!S.empty()) {
		pair<int,int> P = *(S.begin());
		S.erase(P);
		
		int d = P.first;
		int x = P.second;
		
		for(int i=0;i<G[x].size();i++) {
			int neiG = G[x][i].second;
			int neiD = G[x][i].first;
			int newD = neiD+d;
			if(vis[neiG] == 0 && newD < dist[neiG]) {
				
				if(dist[neiG]!=INF) S.erase({ dist[neiG], neiG });
				
				S.insert( {newD, neiG} );
				dist[neiG] = newD;
				
			}
		}
		vis[x] = 1;
	}
	
	printf("%d\n", dist[6399]);

    return 0;
}
