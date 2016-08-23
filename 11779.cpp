#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > graph;
int parent[1001];
vector<int> dijkstra(int src){
	vector<int> dist(n + 1, 0x1fffffff);
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
				parent[next] = now;
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
	}
	int s, d;
	cin >> s >> d;
	vector<int> mincost = dijkstra(s);
	int mcost = mincost[d];
	printf("%d\n", mcost);
	stack<int> st;
	while (d != 0){
		st.push(d);
		d = parent[d];
	}
	printf("%d\n", st.size());
	while (!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");
}
