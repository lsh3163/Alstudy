#include<stdio.h>
#include<iostream>
using namespace std;
int Dp[1234][10];
int main(){
	int N;
	for (int i = 0; i < 10; i++){
		Dp[1][i] = 1;
	}
	for (int i = 2; i <= 1000; i++){
		for (int j = 0; j < 10; j++){
			int sum = 0;
			for (int k = 0; k <= j; k++){
				sum += (Dp[i - 1][k] % 10007);
                sum %= 10007;
			}
			Dp[i][j] = sum;
		}
	}
	cin >> N;
	int answer = 0;
	for (int i = 0; i < 10; i++){
		answer += (Dp[N][i] % 10007);
        answer %= 10007;
	}
	printf("%d", answer);
}
