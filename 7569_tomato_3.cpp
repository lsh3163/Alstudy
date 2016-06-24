#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE 123
using namespace std;
int N, M, H;
int field[SIZE][SIZE][SIZE];
struct point{
	int x;
	int y;
	int z;
	int time;
};
int x_move[6] = { 0, 0, 0, 0, 1, -1 };
int y_move[6] = { 0, 0, 1, -1, 0, 0 };
int z_move[6] = { 1, -1, 0, 0, 0, 0 };
int main(){
	cin >> M; cin >> N; cin >> H;
	queue<point> q;
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= N; j++){
			for (int k = 1; k <= M; k++){
				cin >> field[i][j][k];
				//i높이 j세로 k가로
				if (field[i][j][k] == 1){
					q.push({ i, j, k, 0 });
				}
			}
		}
	}
	int answer = 0;
	while (!q.empty()){
		//높이
		int x = q.front().x;
		//세로
		int y = q.front().y;
		//가로
		int z = q.front().z;
		int time = q.front().time;
		q.pop();
		answer = max(answer, time);
		for (int i = 0; i < 6; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			int nz = z + z_move[i];
			if (nz <= M && ny <= N && nx <= H && nx >= 1 && ny >= 1 && nz >= 1){
				if (field[nx][ny][nz]==0){
					field[nx][ny][nz] = 1;
					q.push({ nx, ny, nz, time + 1 });
				}
			}
		}
	}
	bool check = true;
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= N; j++){
			for (int k = 1; k <= M; k++){
				if (field[i][j][k] == 0){
					check = false;
				}
				if (!check){
					break;
				}
			}
			if (!check){
				break;
			}
		}
		if (!check){
			break;
		}
	}
	if (!check){
		printf("-1");
	}
	else{
		printf("%d", answer);
	}
}
