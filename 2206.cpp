#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int board[1001][1001];
int visited[1001][1001][2];
struct point{
	int x;
	int y;
	bool ch;
};
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
void bfs(int rx, int ry){
	queue<point> q;
	q.push({ rx, ry, false });
	visited[rx][ry][0] = 1;
	while (!q.empty()){
		int now_x = q.front().x;
		int now_y = q.front().y;
		int ch = q.front().ch;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = now_x + x_move[i];
			int ny = now_y + y_move[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
				if (board[nx][ny] == 1){
					if (ch == false && (visited[nx][ny][1]>visited[now_x][now_y][0] + 1)){
						visited[nx][ny][1] = visited[now_x][now_y][0] + 1;
						q.push({ nx, ny, true });
					}
				}
				else if (board[nx][ny] == 0 && (visited[nx][ny][ch]>visited[now_x][now_y][ch] + 1)){
					visited[nx][ny][ch] = visited[now_x][now_y][ch] + 1;
					q.push({ nx, ny, ch });
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 0; k < 2; k++){
				visited[i][j][k] = 0x7fffffff;
			}
		}
	}
	bfs(1, 1);
	int ans = min(visited[n][m][0], visited[n][m][1]);
	if (ans == 0x7fffffff){
		ans = -1;
	}
	printf("%d", ans);
}
