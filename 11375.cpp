#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int source;
int sink;
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
	for (int i = 1; i <= n; i++){
		int cnt;
		cin >> cnt;
		while (cnt--){
			int job;
			cin >> job;
			graph[i].push_back(job);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		fill(visited.begin(), visited.end(), false);
		if (dfs(i)){
			ans++;
		}
	}
	printf("%d", ans);
}
