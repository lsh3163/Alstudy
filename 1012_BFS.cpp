#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#define SIZE 53
using namespace std;
int graph[SIZE][SIZE];
bool visited[SIZE][SIZE];
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
int N, M;
void bfs(int rx,int ry){
	visited[rx][ry] = true;
	queue<pair<int, int > > q;
	q.push(make_pair(rx, ry));
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx < N && nx >= 0 && ny < M && ny >= 0){
				if (!visited[nx][ny] && graph[nx][ny] == 1){
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		//가로 //세로
		cin >> M; cin >> N;
		//그래프 초기화
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				graph[i][j] = 0;
			}
		}
		//visited 초기화
		memset(visited, false, SIZE*SIZE);
		int K;
		cin >> K;
		for (int i = 0; i < K; i++){
			//u=>가로
			//v=>세로
			int u, v;
			cin >> u; cin >> v;
			graph[v][u] = 1;
		}
		int answer = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (!visited[i][j] && graph[i][j]==1){
					answer++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n",answer);
	}
}
