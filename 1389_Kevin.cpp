#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
#define SIZE 123
using namespace std;
int graph[SIZE][SIZE];
bool visited[SIZE];
vector<int> v;
int N, M;
int bfs(int start, int d){
	memset(visited, false, SIZE);
	queue<pair<int, int > > q;
	q.push(make_pair(start, 0));
	visited[start] = true;
	while (!q.empty()){
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		if (now == d){
			return count;
		}
		for (int i = 1; i <= N; i++){
			if (!visited[i] && graph[now][i] == 1){
				visited[i] = true;
				q.push(make_pair(i, count + 1));
			}
		}
	}
}
int main(){
	cin >> N;
	cin >> M;
	while (M--){
		int u, v;
		cin >> u; cin >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	v.resize(N + 1);
	int answer = 0x1fffffff;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			v[i] += bfs(i, j);
		}
		answer = min(answer, v[i]);
	}
	for (int i = 1; i <= N; i++){
		if (v[i] == answer){
			printf("%d", i);
			break;
		}
	}
}
