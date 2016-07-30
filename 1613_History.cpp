#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
vector<vector<pair<int, int> > > FirstGraph;
vector<vector<pair<int, int> > > SecondGraph;
int N, M;
int Question;
int FirstBoard[401][401];
int SecondBoard[401][401];
int Board[401][401];
vector<int> FirstDijkstra(int src){
	vector<int> dist(N + 1, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, src));
	while (!q.empty()){
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (dist[now] < cost){
			continue;
		}
		int len = FirstGraph[now].size();
		for (int i = 0; i < len; i++){
			int next = FirstGraph[now][i].second;
			int nextcost = cost + FirstGraph[now][i].first;
			if (dist[next] > nextcost){
				dist[next] = nextcost;
				q.push(make_pair(-nextcost, next));
			}
		}
	}
	return dist;
}
vector<int> SecondDijkstra(int src){
	vector<int> dist(N + 1, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, src));
	while (!q.empty()){
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (dist[now] < cost){
			continue;
		}
		int len = SecondGraph[now].size();
		for (int i = 0; i < len; i++){
			int next = SecondGraph[now][i].second;
			int nextcost = cost + SecondGraph[now][i].first;
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
	FirstGraph.resize(N + 1);
	SecondGraph.resize(N + 1);
	while (M--){
		int u, v;
		scanf("%d %d",&u,&v);
		FirstGraph[u].push_back(make_pair(1, v));
		SecondGraph[v].push_back(make_pair(1, u));
	}
	cin >> Question;
	for (int i = 1; i <= N; i++){
		vector<int> First = FirstDijkstra(i);
		vector<int> Second = SecondDijkstra(i);
		for (int j = 1; j <= N; j++){
			FirstBoard[i][j] = First[j];
			SecondBoard[i][j] = Second[j];
			if (First[j] == INT_MAX && Second[j] == INT_MAX){
				Board[i][j] = 0;
			}
			if (First[j] != INT_MAX){
				Board[i][j] = -1;
			}
			if (Second[j] != INT_MAX){
				Board[i][j] = 1;
			}
		}
	}
	while (Question--){
		int start, end;
		scanf("%d %d",&start,&end);
		printf("%d\n", Board[start][end]);
	}
}
