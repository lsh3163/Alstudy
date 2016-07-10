#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int field[51][51];
bool visited[51][51];
//가로 M ,세로 N,배추개수 K
int M, N, K;
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
void dfs(int x, int y){
	visited[x][y] = true;
	for (int i = 0; i < 4; i++){
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx < N && nx >= 0 && ny >= 0 && ny < M){
			if (!visited[nx][ny] && field[nx][ny] == 1){
				dfs(nx, ny);
			}
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		//그래프 field, visited 초기화
		memset(field, 0, 51 * 51 * sizeof(int));
		memset(visited, false, 51 * 51);
		cin >> M; cin >> N; cin >> K;
		while (K--){
			int x, y;
			//x는 가로 y는 세로
			cin >> x; cin >> y;
			field[y][x] = 1;
		}
		int answer = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (!visited[i][j] && field[i][j] == 1){
					answer++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", answer);
	}
}
