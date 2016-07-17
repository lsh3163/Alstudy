#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
bool visited[101][101];
int board[101][101];
int h_move[] = { 0, 0, -1, 1 };
int w_move[] = { 1, -1, 0, 0 };
//판 안에 있는지 아닌지 확인하는 함수
bool isPossible(int h, int w){
	if (h > n || w > n || h < 1 || w < 1) return false;
	return true;
}
//1자리에 번호를 매기는 함수(1,2,3,...)
void bfs(int h, int w, int num){
	queue<pair<int, int > > q;
	q.push(make_pair(h, w));
	visited[h][w] = true;
	board[h][w] = num;
	while (!q.empty()){
		int hereH = q.front().first;
		int hereW = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextH = hereH + h_move[i];
			int nextW = hereW + w_move[i];
			if (isPossible(nextH, nextW) && !visited[nextH][nextW] && board[nextH][nextW] != 0){
				q.push(make_pair(nextH, nextW));
				visited[nextH][nextW] = true;
				board[nextH][nextW] = num;
			}
		}
	}
}
int bfs2(int h, int w){
	int ret = 0x1fffffff;
	int dist[101][101];
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int > > q;
	q.push(make_pair(h, w));
	dist[h][w] = 0;
	int hereNum = board[h][w];
	while (!q.empty()){
		int hereH = q.front().first;
		int hereW = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextH = hereH + h_move[i];
			int nextW = hereW + w_move[i];
			if (isPossible(nextH, nextW)){
				if (board[nextH][nextW] != hereNum && board[nextH][nextW]>0){
					ret = min(ret, dist[hereH][hereW]);
				}
				if (board[nextH][nextW] == 0 && dist[nextH][nextW] == -1){
					dist[nextH][nextW] = dist[hereH][hereW] + 1;
					q.push(make_pair(nextH, nextW));
				}
			}
		}
	}
	return ret;
}
int main(void){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> board[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!visited[i][j] && board[i][j] != 0){
				bfs(i, j, ++cnt);
			}
		}
	}
	int mmin = 0x1fffffff;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (board[i][j] != 0){
				mmin = min(bfs2(i, j), mmin);
			}
		}
	}
	printf("%d", mmin);
}
