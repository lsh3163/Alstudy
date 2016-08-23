#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > graph;
int inf = 100000000;
vector<int> dijkstra(int src){
	vector<int> dist(n + 1, inf);
	priority_queue<pair<int, int> > mq;
	mq.push(make_pair(0, src));
	dist[src] = 0;
	while (!mq.empty()){
		int now = mq.top().second;
		int cost = -mq.top().first;
		mq.pop();
		if (dist[now] < cost){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].second;
			int nextcost = graph[now][i].first + cost;
			if (dist[next] > nextcost){
				dist[next] = nextcost;
				mq.push(make_pair(-nextcost, next));
			}
		}
	}
	return dist;
}

int main(){
	cin >> n;
	cin >> m;
	graph.resize(n + 1);
	while (m--){
		int u, v, x;
		cin >> u >> v >> x;
		graph[u].push_back(make_pair(x, v));
		graph[v].push_back(make_pair(x, u));
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int> key1 = dijkstra(1);
	vector<int> key2 = dijkstra(v1);
	vector<int> key3 = dijkstra(v2);
	//Case 1
	int path1 = key1[v1];
	int path2 = key2[v2];
	int path3 = key3[n];
	int ans = path1 + path2 + path3;
	path1 = key1[v2];
	path2 = key3[v1];
	path3 = key2[n];
	int ans1 = path1 + path2 + path3;
	ans = min(ans, ans1);
	if (ans >= inf){
		ans = -1;
	}
	printf("%d", ans);
}
