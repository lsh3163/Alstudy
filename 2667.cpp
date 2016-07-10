#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int field[30][30];
bool visited[30][30];
int N;
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
vector<int> answer;
void bfs(int rx,int ry){
	queue<pair<int, int > > q;
	q.push(make_pair(rx, ry));
	visited[rx][ry] = true;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx >= 1 && ny >= 1 && nx <= N && ny <= N){
				if (!visited[nx][ny] && field[nx][ny] == 1){
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (visited[i][j]){
				ans++;
			}
		}
	}
	answer.push_back(ans);
}
int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			char c;
			cin >> c;
			field[i][j] = c - '0';
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (!visited[i][j] && field[i][j]==1){
				cnt++;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", cnt);
	int len = answer.size();
	vector<int> print;
	print.push_back(answer[0]);
	for (int i = 1; i < len; i++){
		print.push_back(answer[i] - answer[i - 1]);
	}
	sort(print.begin(), print.end());
	for (int i = 0; i < cnt; i++){
		printf("%d\n", print[i]);
	}
}
