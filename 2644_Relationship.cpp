#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int graph[123][123];
bool visited[123];
int bfs(int p1,int p2){
	visited[p1] = true;
	queue<pair<int,int > > q;
	q.push(make_pair(p1, 0));
	while (!q.empty()){
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		if (now == p2){
			return count;
		}
		for (int i = 1; i <= 100; i++){
			if (!visited[i] && graph[now][i] == 1){
				visited[i] = true;
				q.push(make_pair(i, count + 1));
			}
		}
	}
	return -1;
}
int main(){
	int N;
	cin >> N;
	memset(graph, 0, 123 * 123);
	memset(visited, false, 123);
	int person1, person2;
	cin >> person1; cin >> person2;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u;
		cin >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	int answer = bfs(person1, person2);
	printf("%d", answer);
}
