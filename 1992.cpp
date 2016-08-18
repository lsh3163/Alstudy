#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int field[65][65];
bool same(int n, int x, int y){
	for (int i = x; i < x+n; i++){
		for (int j = y; j < y+n; j++){
			if (field[x][y] != field[i][j]){
				return false;
			}
		}
	}
	return true;
}
void solve(int n, int x, int y){
	if (same(n, x, y)){
		printf("%d", field[x][y]);
	}
	else{
		printf("(");
		int m = n / 2;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				solve(m, x + i*m, y + j*m);
			}
		}
		printf(")");
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int x;
			scanf("%1d", &x);
			field[i][j] = x;
		}
	}
	solve(N, 0, 0);
}
