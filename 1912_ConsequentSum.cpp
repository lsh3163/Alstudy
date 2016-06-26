#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

int main(){
	int factor[123123] = {};
	int Dp[123123] = {};
	int answer;
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> factor[i];
	}
	for (int i = 1; i <= N; i++){
		if (Dp[i - 1] + factor[i] > factor[i]){
			Dp[i] = Dp[i - 1] + factor[i];
		}
		else{
			Dp[i] = factor[i];
		}
	}
	answer = Dp[1];
	for (int i = 2; i <= N; i++){
		answer = max(Dp[i], answer);
	
	}
	printf("%d", answer);
}
