#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N = 100;
string nums[100];
string ans;

void add(int x) {
	string num = nums[x];
	
	for(int i=0;i<50;i++) {
		int s = num[i]-'0' + ans[i]-'0';
		
		if(s>=10) {
			ans[i] = (s-10) + '0';

			int k = 1;
			while(ans[i+k] == '9') {
				ans[i+k] = '0';
				k++;
			}
			
			ans[i+k]++;
			
		} else {
			ans[i] = s + '0';
			
		}
		
	}
	
}
int main() {
	freopen("bignum.txt", "r", stdin);
	
	for(int i=0;i<60;i++) ans[i] = '0';
	for(int i=0;i<N;i++) {
		cin >> nums[i];
		reverse(nums[i].begin(), nums[i].end());
		add(i);
	}
	
	
	for(int i=0;i<55;i++) 
		cout << ans[i];
	return 0;
}
