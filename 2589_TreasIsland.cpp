#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N, M;
char field[51][51];
bool visited[51][51];
struct point{
	int x;
	int y;
	int time;
};
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
int bfs(int rx, int ry){
	int answer = 0;
	queue<point> q;
	q.push({ rx, ry, 0 });
	visited[rx][ry] = true;
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		q.pop();
		answer = max(time, answer);
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M){
				if (!visited[nx][ny] && field[nx][ny] == 'L'){
					visited[nx][ny] = true;
					q.push({ nx, ny, time + 1 });
				}
			}
		}
	}
	return answer;
}
int main(){
	cin >> N; cin >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> field[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (field[i][j] == 'L'){
				memset(visited, false, 51 * 51);
				ans = max(ans, bfs(i, j));
			}
		}
	}
	printf("%d", ans);
}
