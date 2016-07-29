#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int N, M;
vector<vector<pair<int, int> > > graph;
int answer[401][401];
vector<int> dijkstra(int src){
	vector<int> dist(N + 1, INT_MAX);
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, src));
	dist[src] = 0;
	while (!q.empty()){
		int nowcost = -q.top().first;
		int now = q.top().second;
		q.pop();
		if (dist[now] < nowcost){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int nextcost = nowcost + graph[now][i].first;
			int next = graph[now][i].second;
			if (dist[next] > nextcost){
				dist[next] = nextcost;
				q.push(make_pair(-nextcost, next));
			}
		}
	}
	return dist;
}
int main(void){
	cin >> N; cin >> M;
	graph.resize(N + 1);
	while (M--){
		int u, v, x;
		cin >> u >> v >> x;
		graph[u].push_back(make_pair(x, v));
	}
	for (int i = 1; i <= N; i++){
		vector<int> result = dijkstra(i);
		for (int j = 1; j <= N; j++){
			answer[i][j] = result[j];
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (answer[i][j] != 0 && answer[i][j] != INT_MAX && answer[j][i]!=0 && answer[j][i]!=INT_MAX){
				ans = min(ans, answer[i][j] + answer[j][i]);
			}
		}
	}
	if (ans == INT_MAX){
		ans = -1;
	}
	printf("%d", ans);
}
