#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<vector<int> > graph;
vector<bool> visited;
vector<int> pred;
bool dfs(int x){
	if (x == -1){
		return true;
	}
	for (int next : graph[x]){
		if (visited[next]) continue;
		visited[next] = true;
		if (dfs(pred[next])){
			pred[next] = x;
			return true;
		}
	}
	return false;
}
int main(){
	cin >> n >> m;
	int k = max(n, m);
	graph.resize(k + 1);
	visited.resize(k + 1);
	pred.resize(k + 1, -1);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		fill(visited.begin(), visited.end(),false);
		if (dfs(i)){
			ans++;
		}
	}
	printf("%d", ans);
}
