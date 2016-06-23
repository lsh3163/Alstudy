#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
bool visited[321][321];
int N;
struct POINT{
	int x;
	int y;
	int time;
};
int x_move[8] = {1,2,2,1,-1,-2,-2,-1};
int y_move[8] = {2,1,-1,-2,2,1,-1,-2};
int bfs(int sx,int sy,int ex,int ey){
	visited[sx][sy] = true;
	queue<POINT> q;
	q.push({ sx, sy, 0 });
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().time;
		q.pop();
		if (x == ex && y == ey){
			return t;
		}
		for (int i = 0; i < 8; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N){
				if (!visited[nx][ny]){
					visited[nx][ny] = true;
					q.push({ nx, ny, t + 1 });
				}
			}
		}
	
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		memset(visited, false, 321 * 321);
		int startx, starty;
		cin >> startx; cin >> starty;
		int endx, endy;
		cin >> endx; cin >> endy;
		int answer = bfs(startx, starty, endx, endy);
		printf("%d\n",answer);
	}
}
