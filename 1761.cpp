#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int m;
vector<vector<pair<int, int > > > tree;
int parent[40001];
bool visited[40001];
int depth[40001];
int dist[40001];
void bfs(int src){
	dist[src] = 0;
	depth[src] = 0;
	parent[src] = 0;
	visited[src] = true;
	queue<int> q;
	q.push(src);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = tree[now].size();
		for (int i = 0; i < len; i++){
			int next = tree[now][i].second;
			if (!visited[next]){
				visited[next] = true;
				parent[next] = now;
				depth[next] = depth[now] + 1;
				dist[next] = dist[now] + tree[now][i].first;
				q.push(next);
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
		int u, v, x;
		cin >> u >> v >> x;
		tree[u].push_back(make_pair(x, v));
		tree[v].push_back(make_pair(x, u));
	}
	bfs(1);
	cin >> m;
	while (m--){
		int u, v;
		cin >> u >> v;
		printf("%d\n", dist[u] + dist[v] - 2 * dist[lca(u, v)]);
	}
}
