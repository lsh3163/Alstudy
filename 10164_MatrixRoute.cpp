#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int graph[20][20];
bool visited[20][20];
//행, 열
int N, M, K;
int midr, midc;
int input;
int x_move[] = { 1, 0 };
int y_move[] = { 0, 1 };
int answer1 = 0;
int answer2 = 0;
void dfs1(int x, int y){
	if (x == midr && y == midc){
		answer1++;
	}
	for (int i = 0; i < 2; i++){
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx >= 1 && nx <= midr && ny <= midc && ny >= 1){
			if (!visited[nx][ny]){
				visited[nx][ny] = true;
				dfs1(nx, ny);
				visited[nx][ny] = false;
			}
		}
	}
}
void dfs2(int x, int y){
	if (x == N && y == M){
		answer2++;
	}
	for (int i = 0; i < 2; i++){
		int nx = x + x_move[i];
		int ny = y + y_move[i];
		if (nx >= midr && nx <= N && ny <= M && ny >= midc){
			if (!visited[nx][ny]){
				visited[nx][ny] = true;
				dfs2(nx, ny);
				visited[nx][ny] = false;
			}
		}
	}
}
int main(){
	cin >> N; cin >> M; cin >> K;
	input = 1;
	//그래프 생성
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			graph[i][j] = input;
			input++;
			if (graph[i][j] == K){
				midr = i;
				midc = j;
			}
		}
	}
	int answer = 0;
	if (midr == 0 && midc==0){
		dfs2(1, 1);
		answer = answer2;
	}
	else{
		dfs1(1, 1);
		dfs2(midr, midc);
		answer = answer1*answer2;
	}
	printf("%d", answer);
}
