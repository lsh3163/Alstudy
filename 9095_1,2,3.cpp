#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int S;
int memo[15];
int solve(int sum){
	if (memo[sum] > 0){
		return memo[sum];
	}
	if (sum == S){
		return 1;
	}
	else if (sum > S){
		return 0;
	}
	memo[sum] += solve(sum + 1);
	memo[sum] += solve(sum + 2);
	memo[sum] += solve(sum + 3);
	return memo[sum];
}
int main(){
	int T;
	cin >> T;
	while (T--){
		memset(memo, 0, 15 * sizeof(int));
		cin >> S;
		int answer = solve(0);
		printf("%d\n", answer);
	}
}
