#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<pair<int, int> > > graph;
vector<int> score;
vector<int> dijkstra(int src){
	vector<int> dist(N + 1, 0x1fffffff);
	dist[src] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(src, 0));
	while (!q.empty()){
		int now = q.top().first;
		int cost = -q.top().second;
		q.pop();
		if (dist[now] < cost){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].first;
			int nextcost = graph[now][i].second + cost;
			if (dist[next] > nextcost){
				dist[next] = nextcost;
				q.push(make_pair(next, -nextcost));
			}
		}
	}
	return dist;
}
int main(void){
	cin >> N;
	graph.resize(N + 1);
	score.resize(N + 1);
	while (true){
		int u, v;
		cin >> u; cin >> v;
		if (u == -1 && v == -1){
			break;
		}
		graph[u].push_back(make_pair(v, 1));
		graph[v].push_back(make_pair(u, 1));
	}
	//회장 점수
	int mmin = 0x1fffffff;
	for (int i = 1; i <= N; i++){
		vector<int> result = dijkstra(i);
		int mmax = 0;
		int len = result.size();
		for (int j = 0; j < len; j++){
			if (result[j] != 0x1fffffff){
				mmax = max(mmax, result[j]);
			}
		}
		score[i] = mmax;
		mmin = min(mmin, score[i]);
	}
	int how_many = 0;
	vector<int> print;
	for (int i = 1; i <= N; i++){
		if (score[i] == mmin){
			print.push_back(i);
			how_many++;
		}
	}
	printf("%d %d\n", mmin, how_many);
	int len = print.size();
	for (int i = 0; i < len; i++){
		printf("%d ", print[i]);
	}
}

