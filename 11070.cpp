#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<climits>
using namespace std;
int T;
int n;
int m;
int main(){
	cin >> T;
	while (T--){
		cin >> n >> m;
		vector<long long> group_ad(n + 1, 0);
		vector<long long> group_lose(n + 1, 0);
		vector<long long> groupW(n + 1, 0);
		while (m--){
			int a, b;
			long long p, q;
			cin >> a >> b >> p >> q;
			group_ad[a] += p;
			group_ad[b] += q;
			group_lose[a] += q;
			group_lose[b] += p;
		}
		long long maxans = -1;
		long long minans = LLONG_MAX;
		for (int i = 1; i <= n; i++){
			if (group_ad[i] == 0 && group_lose[i] == 0){
				groupW[i] = 0;
			}
			else{
				groupW[i] = (group_ad[i] * group_ad[i]) * 1000;
				groupW[i] /= (group_ad[i] * group_ad[i] + group_lose[i] * group_lose[i]);
			}
			maxans = max(groupW[i], maxans);
			minans = min(groupW[i], minans);
		}
		long long firans = maxans;
		long long sedans = minans;
		printf("%lld\n%lld\n", firans, sedans);
	}
}
