#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int M, N;
int field[1001][1001];
bool visited[1001][1001];

struct point{
	int x;
	int y;
	int time;
};

int x_move[] = { 1, -1, 0, 0 };
int y_move[] = { 0, 0, -1, 1 };

int bfs(){

	queue<point> q;
	
	int answer = 0;
	bool check = true;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (field[i][j] == 1){
				q.push({ i, j, 0 });
				visited[i][j] = true;
			}
			if (field[i][j] == 0){
				check = false;
			}
		}
	}
	if (check){
		return answer;
	}

	answer = 0;

	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		answer = max(answer, time);
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= M){
				if (!visited[nx][ny] && field[nx][ny] == 0){
					visited[nx][ny] = true;
					field[nx][ny] = 1;
					q.push({ nx, ny, time + 1 });
				}
			}
		}
	}

	check = true;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (field[i][j] == 0){
				check = false;
			}
		}
	}
	if (!check){
		answer = -1;
	}

	return answer;
}
int main(void){
	cin >> M; cin >> N;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> field[i][j];
		}
	}

	int answer = bfs();
	
	printf("%d", answer);
}
