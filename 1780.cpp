#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int N;
int cnt[] = { 0, 0, 0 };
int field[3001][3001];
bool same(int x,int y,int m){
	for (int i = x; i < x + m; i++){
		for (int j = y; j < y + m; j++){
			if (field[x][y] != field[i][j]){
				return false;
			}
		}
	}
	return true;
}
void solve(int x, int y, int n){
	if (same(x, y, n)){
		cnt[field[x][y] + 1]++;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			solve(x + m*i, y + m*j, m);
		}
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> field[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i <= 2; i++){
		printf("%d\n", cnt[i]);
	}
}
