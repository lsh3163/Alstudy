#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
int graph[123][123];
bool visited[123][123];
int N; int M;
struct point{
	int x;
	int y;
	int time;

};
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
int bfs(int root_x,int root_y){
	memset(visited, false, 123 * 123);
	queue<point> q;
	visited[root_x][root_y] = true;
	q.push({ root_x, root_y, 0 });
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().time;
		if (x == N && y == M){
			return t + 1;
		}
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx <= N && ny <= M && nx >= 1 && ny >= 1){
				if (!visited[nx][ny] && graph[nx][ny] > 0){
					visited[nx][ny] = true;
					point p = { nx, ny, t + 1 };
					q.push(p);
				}
			}
		}
	}
}
int main(){
	cin >> N; cin >> M;
	memset(graph, 0, 123 * 123);
	for (int i = 0; i < N; i++){
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++){
			graph[i + 1][j + 1] = s[j] - '0';
		}
	}
	int answer = bfs(1, 1);
	printf("%d", answer);
}
