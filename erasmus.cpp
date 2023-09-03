#include <stdio.h>
#include <vector>
#include <algorithm>
#define max_n 1010
#define max_m 10010
using namespace std;

int places[max_n];
vector<pair<vector<int>,int > > fitites;
pair<int, int> final[max_m];

bool compare1(pair<vector<int>,int > arr1, pair<vector<int>,int > arr2){
	return arr1.first[0] > arr2.first[0];
}

bool compare2(pair<int,int> arr1, pair<int,int> arr2){
	return arr1.second < arr2.second;
}

int main(){
	freopen("erasmus.in","r", stdin);
	freopen("erasmus.out","w", stdout);

	int N,M,panep,temp;
	scanf("%d %d", &N ,&M);
	for(int i=0; i<N; i++) scanf("%d", &places[i]);
	
	for(int i=0; i<M; i++){
		fitites.push_back(pair<vector<int>,int >());
		fitites[i].second = i;
		
		scanf("%d", &temp);
		fitites[i].first.push_back(temp);
		
		scanf("%d", &panep);
		for(int j=0; j<panep; j++){
			scanf("%d", &temp);
			fitites[i].first.push_back(temp);
		}
	}
	sort(fitites.begin(), fitites.end(), compare1);


	for(int i=0; i<M; i++){
		for(int j=1; j<fitites[i].first.size(); j++){
			if(places[ fitites[i].first[j]-1 ] > 0){
				places[ fitites[i].first[j]-1 ]--;
				final[i].first=fitites[i].first[j];
				final[i].second=fitites[i].second;
				break;
			}
		}
		if(final[i].first == 0) final[i].second=fitites[i].second;
	}


	sort(final, final+M, compare2);
	for(int i=0; i<M; i++){
		if(final[i].first == 0) printf("NONE\n");
		else{
			printf("%d\n", final[i].first);
		}
	}
	
	return 0;
}
