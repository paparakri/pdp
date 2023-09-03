#include <stdio.h>
#include <algorithm>
#define max_N 2000010
using namespace std; 

int arr[max_N];

int getSubarraySum(int sum[], int i, int j){ 
	if (i == 0) 
		return sum[j]; 
	else
		return (sum[j] - sum[i - 1]); 
}

int maximumSumTwoNonOverlappingSubarray(int N, int K){ 

	int sum[N];
	int S=0;
	
	sum[0] = arr[0]; 
	for (int i = 1; i < N; i++) 
		sum[i] = sum[i - 1] + arr[i]; 

	pair<int, int> resIndex = make_pair(N - 2 * K, N - K); 

	int maxSum2Subarray = getSubarraySum(sum, N - 2 * K, N - K - 1) + getSubarraySum(sum, N - K, N - 1); 

	pair<int, int> secondSubarrayMax = make_pair(N - K, getSubarraySum(sum, N - K, N - 1)); 

	for (int i = N - 2 * K - 1; i >= 0; i--){
		int cur = getSubarraySum(sum, i + K, i + 2 * K - 1); 

		if (cur >= secondSubarrayMax.second) 
			secondSubarrayMax = make_pair(i + K, cur); 

		cur = getSubarraySum(sum, i, i + K - 1) + 
			secondSubarrayMax.second; 

		if (cur >= maxSum2Subarray){ 
			maxSum2Subarray = cur; 
			resIndex = make_pair(i, secondSubarrayMax.first); 
		} 
	} 

	for (int i = resIndex.first; i < resIndex.first + K; i++){
		S += arr[i];
	}
	
	for (int i = resIndex.second; i < resIndex.second + K; i++){
		S += arr[i];
	}
	
	return S;
} 

int main() 
{
	freopen("shops.in","r",stdin);
	freopen("shops.out","w",stdout);
	
	int N,K,a;
	
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		arr[i]=a;
	}

	int result = maximumSumTwoNonOverlappingSubarray(N, K);
	
	printf("%d", result);

	return 0; 
}
