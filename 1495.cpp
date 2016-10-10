#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N, S, M;
int vol[101];
int memo[101][1001];
bool check[101][1001];
//곡의 개수가 n개일 때 S
int solve(int n, int s){
	if (n == N + 1){
		if (s <= M && s >= 0){
			return s;
		}
		return -1;
	}
	if (s > M || s < 0){
		return -1;
	}
	int &ret = memo[n][s];
	if (check[n][s]){
		return ret;
	}
	check[n][s] = true;
	ret = max(solve(n + 1, s + vol[n]), solve(n + 1, s - vol[n]));
	return ret;
}
int main(){
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++){
		cin >> vol[i];
	}
	int ans = solve(1, S);
	if (ans < 0 || ans>M){
		ans = -1;
	}
	printf("%d", ans);
	return 0;
}
