#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<vector<int > > graph;
vector<bool> visited;

int N, M;

void dfs(int n){
	visited[n] = true;
	int len = graph[n].size();
	for (int i = 0; i < len; i++){
		int there = graph[n][i];
		if (!visited[there]){
			dfs(there);
		}
	}
	v.push_back(n);
}
int main(void){
	cin >> N; cin >> M;
	graph.resize(N + 1);
	visited.resize(N + 1, false);
	while (M--){
		int u, v;
		cin >> u; cin >> v;
		graph[u].push_back(v);
	}
	for (int i = 1; i <= N; i++){
		if (!visited[i]){
			dfs(i);
		}
	}
	int len = v.size();
	for (int i = len - 1; i >= 0; i--){
		printf("%d ", v[i]);
	}
}
