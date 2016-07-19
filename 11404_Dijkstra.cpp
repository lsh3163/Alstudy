#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int > > > graph;
int answer[101][101];
vector<int> dijkstra(int src){
	vector<int> cost(N + 1, 0x1fffffff);
	cost[src] = 0;
	//정점,비용
	priority_queue<pair<int, int > > q;
	q.push(make_pair(src, 0));
	while (!q.empty()){
		int now = q.top().first;
		int C = -q.top().second;
		q.pop();
		if (cost[now] < C){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].first;
			int nextcost = graph[now][i].second + C;
			if (cost[next] > nextcost){
				cost[next] = nextcost;
				q.push(make_pair(next, -nextcost));
			}
		}
	}
	return cost;
}
int main(void){
	cin >> N; cin >> M;
	graph.resize(N + 1);
	while (M--){
		int u, v, x;
		cin >> u; cin >> v; cin >> x;
		graph[u].push_back(make_pair(v, x));
	}
	for (int i = 1; i <= N; i++){
		vector<int> Ans = dijkstra(i);
		for (int j = 1; j <= N; j++){
			answer[i][j] = Ans[j];
		}
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
}
