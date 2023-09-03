#include <stdio.h>
#define maxN 100010
using namespace std;

int servers[maxN] = {0};

int main(){
	int N, num;

	freopen("sch.in", "r", stdin);
	//freopen("sch.out", "w", stdout);

	scanf("%d", &N);

	for (int i=0; i<N; i++) {
		scanf("%d", &num);
		servers[num]++;
	}

	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int index1, index2, index3;

	for (int i=0; i<N; i++) {
		printf("Server %d was visited %d times\n", i, servers[i]);
		if(servers[i] > max1){
			if(max1 > max2){
				max2 = max1;
				index2 = index1;
			}
			max1 = servers[i];
			index1 = i;
		} else if(servers[i] > max2){
			if(max2 > max3){
				max3 = max2;
				index3 = index2;
			}
			max2 = servers[i];
			index2 = i;
		} else if(servers[i] > max3){
			max3 = servers[i];
			index3 = i;
		}
	}

	printf("%d %d %d\n", index1, index2, index3);
	return 0;
}