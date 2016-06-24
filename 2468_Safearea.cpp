#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
//2차원 배열의 행과 열의 개수 N
int N;
int field[123][123];
bool visited[123][123];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };
void bfs(int rx,int ry,int h){
	queue<pair<int, int > > q;
	visited[rx][ry] = true;
	q.push(make_pair(rx, ry));
	while (!q.empty()){
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int next_x = now_x + x_move[i];
			int next_y = now_y + y_move[i];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N){
				if (!visited[next_x][next_y] && field[next_x][next_y] - h>0){
					visited[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}
int main(){
	
	cin >> N;
	int answer = 0;
	int max_h = 0;
	//가장 최고높이를 입력받으면서 구함
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> field[i][j];
			max_h = max(field[i][j], max_h);
		}
	}
	//높이 1부터 최고높이까지 for문돌리면서 섬의 개수를 구함
	for (int i = 0; i <= max_h; i++){
		memset(visited, false, 123 * 123);
		int island = 0;
		for (int j = 1; j <= N; j++){
			for (int k = 1; k <= N; k++){
				if (!visited[j][k] && (field[j][k]-i>0)){
					island++;
					bfs(j, k, i);
				}
			}
		}
		answer = max(answer, island);

	}
	printf("%d", answer);
}
