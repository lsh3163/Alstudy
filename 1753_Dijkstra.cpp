#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E;
vector<vector<pair<int,int > > > graph;
vector<int> dijkstra(int Start){
	vector<int> dist(V + 1, 0x1fffffff);
	dist[Start] = 0;
	
	//정점,거리
	priority_queue<pair<int, int > > my_q;
	my_q.push(make_pair(Start, 0));
	while (!my_q.empty()){
		int x = my_q.top().first;
		int d = -my_q.top().second;
		my_q.pop();
		
		if (dist[x] < d){
			continue;
		}

		int len = graph[x].size();
		for (int i = 0; i < len; i++){
			int nextX = graph[x][i].first;
			int nextD = graph[x][i].second + d;
			if (nextD < dist[nextX]){
				dist[nextX] = nextD;
				my_q.push(make_pair(nextX, -nextD));
			}
		}
	}
	return dist;
}
int main(void){
	
	cin >> V; cin >> E;
	int Start;
	cin >> Start;

	graph.resize(V + 1);
	
	while (E--){
		int u, v, x;
		cin >> u; cin >> v; cin >> x;
		graph[u].push_back(make_pair(v, x));
	}
	vector<int> ans = dijkstra(Start);
	for (int i = 1; i <= V; i++){
		if (ans[i] == 0x1fffffff){
			printf("INF\n");
		}
		else{
			printf("%d\n", ans[i]);
		}
	}
}

