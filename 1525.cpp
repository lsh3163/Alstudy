#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#include<map>
#include<string>
using namespace std;
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
map<int, int> dist;
void bfs(int start){
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()){
		int nownum = q.front();
		string now = to_string(nownum);
		q.pop();
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
				string next = now;
				swap(next[3 * x + y], next[nx * 3 + ny]);
				int num = stoi(next);
				if (dist.count(num) == 0){
					dist[num] = dist[nownum] + 1;
					q.push(num);
				}
			}
		}
	}
}
int main(){
	int start = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			int input;
			cin >> input;
			if (input == 0){
				input = 9;
			}
			start = start * 10 + input;
		}
	}
	bfs(start);
	if (dist.count(123456789) == 0){
		dist[123456789] = -1;
	}
	printf("%d", dist[123456789]);
}
