#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define mod 1000000007
using namespace std;
long long memo[101][101][101];
//빌딩 n,왼쪽 l,오른쪽 r일 때 가능한 빌딩 배치 수
long long solve(int n, int l, int r){
    if(n<1){
        return 0;
    }
	if (n == 1){
		if (l == 1 && r == 1){
			return 1;
		}
		return 0;
	}
	long long &ret = memo[n][l][r];
	if (ret != -1){
		return ret;
	}
	ret = solve(n - 1, l - 1, r) + solve(n - 1, l, r - 1);
	ret += solve(n - 1, l, r)*(n - 2);
	ret %= mod;
	return ret;
}
int main(){
	memset(memo, -1, sizeof(memo));
	int N, L, R;
	cin >> N >> L >> R;
	printf("%lld", solve(N, L, R)%mod);
	return 0;
}
