#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int m;
vector<vector<int> > tree;
int parent[50001];
int depth[50001];
bool visited[50001];
void bfs(int src){
	queue<int> q;
	parent[src] = 0;
	depth[src] = 0;
	visited[src] = true;
	q.push(src);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = tree[now].size();
		for (int i = 0; i < len; i++){
			int next = tree[now][i];
			if (!visited[next]){
				q.push(next);
				visited[next] = true;
				parent[next] = now;
				depth[next] = depth[now] + 1;
			}
		}
	}
}
int lca(int x, int y){
	if (depth[x] < depth[y]){
		swap(x, y);
	}
	while (depth[x] != depth[y]){
		x = parent[x];
	}
	while (x != y){
		x = parent[x];
		y = parent[y];
	}
	return x;
}
int main(){
	cin >> n;
	tree.resize(n + 1);
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	bfs(1);
	cin >> m;
	while (m--){
		int u, v;
		cin >> u >> v;
		printf("%d\n", lca(u, v));
	}
}
