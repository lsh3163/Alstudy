#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int N, M, K;
//dist[i][j] i도시에 j는 포장한 도로 개수
int dist[10001][21];
//check 배열
bool check[10001][21];
//dijkstra 에 활용할 인접리스트
vector<vector<pair<int, int> > > graph;
void dijkstra(int root){
	dist[root][0] = 0;
	//cost,now,step
	priority_queue<tuple<int, int,int> > mq;
	mq.push(make_tuple(0, 1, 0));
	while (!mq.empty()){
		//cost
		int cost = -get<0>(mq.top());
		int now = get<1>(mq.top());
		int step = get<2>(mq.top());
		mq.pop();
		if (check[now][step]){
			continue;
		}
		check[now][step] = true;
		for (auto &p : graph[now]){
			int next = p.second;
			//포장할 개수가 K개 미만이고 포장을 한 게 갱신할 값이면
			if (step + 1 <= K && dist[next][step + 1] > dist[now][step]){
				dist[next][step + 1] = dist[now][step];
				mq.push(make_tuple(-dist[next][step + 1], next, step + 1));
			}
			if (dist[next][step] > dist[now][step] + p.first){
				dist[next][step] = dist[now][step] + p.first;
				mq.push(make_tuple(-dist[next][step], next, step));
			}
		}
	}
}
int main(){
	cin >> N >> M >> K;
	graph.resize(N + 1);
	while (M--){
		int u, v, x;
		cin >> u >> v >> x;
		//양 방향이므로
		graph[u].push_back(make_pair(x, v));
		graph[v].push_back(make_pair(x, u));
	}
	//dist inf로 초기화
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= K; j++){
			dist[i][j] = 0x7fffffff;
		}
	}
	//1번에서 시작해서 n번에 도착
	dijkstra(1);
	int ans = 0x7fffffff;
	for (int i = 0; i <= K; i++){
		if (check[N][i]){
			ans = min(ans, dist[N][i]);
		}
	}
	printf("%d", ans);
	return 0;
}
