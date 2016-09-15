#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int n, m;
struct point{
	int from;
	int to;
	int cost;
	bool operator < (const point &other){
		return cost < other.cost;
	}
};
int parent[100001];

int find(int x){
	if (x == parent[x]){
		return x;
	}
	return parent[x] = find(parent[x]);
}
void Union(int u, int v){
	u = find(u);
	v = find(v);
	if (u != v){
		parent[v] = u;
	}
}
int main(){
	cin >> n >> m;
	vector<point> group;
	group.resize(m);
	int k = -1;
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}
	for (int i = 0; i < m; i++){
		int u, v, x;
		cin >> u >> v >> x;
		group[i].from = u;
		group[i].to = v;
		group[i].cost = x;
		k = max(x, k);
	}
	sort(group.begin(), group.end());
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++){
		int from = group[i].from;
		int to = group[i].to;
		int cost = group[i].cost;
		from = find(from);
		to = find(to);
		if (from != to){
			Union(from, to);
			ans += cost;
			cnt++;
		}
		if (cnt == n - 2){
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
