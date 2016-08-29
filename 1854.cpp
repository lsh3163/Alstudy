#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<pair<int, int> > > graph;
int n;
int m;
int k;
priority_queue<int> dist[10001];
void dijkstra(int src){
	dist[src].push(0);
	priority_queue<pair<int, int > > myqueue;
	myqueue.push(make_pair(0, src));
	while (!myqueue.empty()){
		auto p = myqueue.top();
		int now = p.second;
		int cost = -p.first;
		myqueue.pop();
		for (auto n : graph[now]){
			int next = n.second;
			int nextcost = n.first + cost;
			if (dist[next].size() < k || dist[next].top() > nextcost){
				if (dist[next].size() == k){
					dist[next].pop();
				}
				dist[next].push(nextcost);
				myqueue.push(make_pair(-nextcost,next));
			}
		}
	}
}
int main(){
	cin >> n >> m >> k;
	graph.resize(n + 1);
	while (m--){
		int u, v, x;
		cin >> u >> v >> x;
		graph[u].push_back(make_pair(x, v));
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++){
		if (dist[i].size() != k){
			printf("-1\n");
		}
		else{
			printf("%d\n", dist[i].top());
		}
	}
}
