#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N;
int field[101][101];
bool visited[101][101];
struct point{
	int h;
	int w;
};
int h_move[] = { 0, 0, -1, 1 };
int w_move[] = { 1, -1, 0, 0 };

void Making_Land(int h,int w,int num){
	visited[h][w] = true;
	queue<point> q;
	q.push({ h, w });
	field[h][w] = num;
	while (!q.empty()){
		int nowH = q.front().h;
		int nowW = q.front().w;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextH = nowH + h_move[i];
			int nextW = nowW + w_move[i];
			if (nextH >= 1 && nextH <= N && nextW >= 1 && nextW <= N){
				if (!visited[nextH][nextW] && field[nextH][nextW]>0){
					field[nextH][nextW] = num;
					visited[nextH][nextW] = true;
					q.push({ nextH, nextW });
				}
			}
		}
	}
}
int Bridge(int h,int w){
	int dist[101][101];
	memset(dist, -1, sizeof(dist));
	int hereNum = field[h][w];
	queue<point> q;
	q.push({ h, w });
	dist[h][w] = 0;
	int ret = 0x1fffffff;
	while (!q.empty()){
		int H = q.front().h;
		int W = q.front().w;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextH = H + h_move[i];
			int nextW = W + w_move[i];
			if (nextH >= 1 && nextH <= N && nextW <= N && nextW >= 1){
				if (field[nextH][nextW]>0){
					if (field[nextH][nextW] != hereNum){
						ret = min(ret, dist[H][W]);
					}
				}
				else if (field[nextH][nextW]==0){
					if (dist[nextH][nextW] == -1 ){
						dist[nextH][nextW] = dist[H][W] + 1;
						q.push({ nextH, nextW });
					}
				}
			}
		}
	}
	return ret;
}
int main(void){
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> field[i][j];
		}
	}
	int NumOfLand = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (!visited[i][j] && field[i][j] > 0){
				NumOfLand++;
				Making_Land(i, j, NumOfLand);
			}
		}
	}
	int answer = 0x1fffffff;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (field[i][j] > 0){
				answer = min(answer, Bridge(i, j));
			}
		}
	}
	printf("%d", answer);
}
