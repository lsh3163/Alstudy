#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int field[1234][1234];
int memo[1234][1234];
int N, M;
int x_move[] = { -1, -1, 0 };
int y_move[] = { 0, -1, -1 };
int solve(int n, int m){
	if (n == 1 && m == 1){
		return field[1][1];
	}
	int &ret = memo[n][m];
	if (ret != -1){
		return ret;
	}
	ret = field[n][m];
	for (int i = 0; i < 3; i++){
		int x = n + x_move[i];
		int y = m + y_move[i];
		if (x >= 1 && x <= N && y >= 1 && y <= M){
			ret = max(ret, field[n][m] + solve(x, y));
		}
	}
	return ret;
}
int main(){
	cin >> N; cin >> M;
	memset(memo, -1, 1234 * 1234 * sizeof(int));
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> field[i][j];
		}
	}
	int answer = solve(N, M);
	printf("%d", answer);
}
