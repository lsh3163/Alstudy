#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int board[1001][1001];
int memo[1001][1001][3];
bool check[1001][1001][3];
int N, M;
//위 0 왼쪽 1 오 2
int solve(int x, int y, int r){
	if (x < 1 || y < 1 || x > N || y > M){
		return -1000*1000*101;
	}
	if (x == 1 && y == 1){
		return board[1][1];
	}
	int &ret = memo[x][y][r];
	if (check[x][y][r]){
		return ret;
	}
	check[x][y][r] = true;
	if (r == 0){
		ret = max(solve(x - 1, y, 0), solve(x - 1, y, 1));
		ret = max(ret, solve(x - 1, y, 2));
		ret += board[x][y];
	}
	else if (r == 1){
		ret = max(solve(x, y - 1, 0), solve(x, y - 1, 1)) + board[x][y];
	}
	else if (r == 2){
		ret = max(solve(x, y + 1, 0), solve(x, y + 1, 2)) + board[x][y];
	}
	return ret;
}
int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> board[i][j];
		}
	}
	memset(check, false, sizeof(check));
	int ans = max(solve(N, M, 0), solve(N, M, 1));
	printf("%d", ans);
	return 0;
}
