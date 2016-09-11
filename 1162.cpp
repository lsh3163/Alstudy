#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<tuple>
using namespace std;
vector<vector<pair<int, int> > > graph;
int n, m;
int k;
int dist[10001][31];
void dijkstra(int src){
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 30; j++){
			dist[i][j] = 0x7fffffff;
		}
	}
	//cost,now,ch
	priority_queue<tuple<int,int,int> > mq;
	dist[src][0] = 0;
	mq.push(make_tuple(0, src, 0));
	while (!mq.empty()){
		auto p = mq.top();
		int cost = -get<0>(p);
		int now = get<1>(p);
		int step = get<2>(p);
		mq.pop();
		if (dist[now][step] < cost){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].second;
			if (step + 1 <= k && dist[next][step + 1]>dist[now][step]){
				dist[next][step + 1] = dist[now][step];
				mq.push(make_tuple(-dist[next][step + 1], next, step + 1));
			}
			if (dist[next][step] > dist[now][step] + graph[now][i].first){
				dist[next][step] = dist[now][step] + graph[now][i].first;
				mq.push(make_tuple(-dist[next][step], next, step));
			}
		}
	}
}
int main(){
	cin >> n >> m >> k;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++){
		int u, v, x;
		cin >> u >> v >> x;
		graph[u].push_back(make_pair(x, v));
		graph[v].push_back(make_pair(x, u));
	}
	dijkstra(1);
	int ans = 0x7fffffff;
	for (int i = 1 ; i <= k; i++){
		ans = min(ans, dist[n][i]);
	}
	printf("%d", ans);
	return 0;
}
