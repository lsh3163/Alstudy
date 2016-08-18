#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
map<vector<int>, int> dist;
vector<int> sorted;
int first_zero;
int x_move[] = { 0, 0, -1, 1 };
int y_move[] = { 1, -1, 0, 0 };
int bfs(vector<int> &start){
	sorted = start;
	sort(sorted.begin(), sorted.end());
	//9의 위치가 second
	queue<pair<vector<int>,int> > q;
	q.push(make_pair(start,first_zero));
	dist[start] = 0;
	while (!q.empty()){
		vector<int> now = q.front().first;
		int zero_index = q.front().second;
		if (now == sorted){
			return dist[now];
		}
		q.pop();
		//방향은 상하좌우
		int x = zero_index / 3;
		int y = zero_index % 3;
		for (int i = 0; i < 4; i++){
			int nx = x + x_move[i];
			int ny = y + y_move[i];
			if (nx>=0 && nx<3 && ny>=0 &&ny<3){
				vector<int> next = now;
				swap(next[3 * x + y], next[3 * nx + ny]);
				if (dist.count(next) == 0){
					q.push(make_pair(next, 3 * nx + ny));
					dist[next] = dist[now] + 1;
				}
			}
		}
	}
	return -1;
}
int main(){
	vector<int> start;
	for (int i = 0; i < 9; i++){
		int input;
		cin >> input;
		if (input == 0){
			input = 9;
			first_zero = i;
		}
		start.push_back(input);
	}
	int answer = bfs(start);
	printf("%d", answer);
}
