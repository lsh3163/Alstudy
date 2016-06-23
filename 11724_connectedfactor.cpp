#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int > > graph;
bool visited[1234];
int N; int M;
void bfs(int root){
	visited[root] = true;
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int now = q.front();
		int len = graph[now].size();
		q.pop();
		for (int i = 0; i < len; i++){
			if (!visited[graph[now][i]]){
				visited[graph[now][i]] = true;
				q.push(graph[now][i]);
			}
		}
	}
}
int main(){
	cin >> N; cin >> M;
	graph.resize(N + 1);
	for (int i = 1; i <= M; i++){
		int u, v;
		cin >> u; cin >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(visited, false, 1234);
	int count = 0;
	for (int i = 1; i <= N; i++){
		if (!visited[i]){
			bfs(i);
			count++;
		}
	}
	printf("%d", count);
}
