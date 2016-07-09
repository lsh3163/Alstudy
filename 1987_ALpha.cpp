#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//주어진 자연수 R과 C
char field[21][21];
int R, C;
bool selected[26];
bool visited[21][21];
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
int answer = 0;
void dfs(int x, int y, int length){
	selected[field[x][y] - 'A'] = true;
	answer = max(answer, length);
	for (int i = 0; i < 4; i++){
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx >= 1 && nx <= R && ny <= C && ny >= 1){
			if (!selected[field[nx][ny] - 'A']){
				selected[field[nx][ny] - 'A'] = true;
				dfs(nx, ny, length + 1);
				selected[field[nx][ny] - 'A'] = false;
			}
		}
	}
}
int main(){
	cin >> R; cin >> C;
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cin >> field[i][j];
		}
	}
	dfs(1, 1, 1);
	printf("%d", answer);
}
