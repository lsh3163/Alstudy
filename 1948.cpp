#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n, m;
//밥 다 먹는데 걸리는 최소시간 
vector<vector<pair<int, int> > > graph1;

//간선의 개수 찾기
vector<vector<pair<int, int> > > graph2;
int indegree1[10001];
int indegree2[10001];
int dist[10001];
bool possible[10001];
int s, d;
int ans;
void bfs1(){
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (indegree1[i] == 0){
			q.push(i);
		}
	}
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = graph1[now].size();
		for (int i = 0; i < len; i++){
			int next = graph1[now][i].second;
			indegree1[next]--;
			if (indegree1[next] == 0){
				q.push(next);
			}
			if (dist[now] + graph1[now][i].first>dist[next]){
				dist[next] = dist[now] + graph1[now][i].first;
			}
		}
	}
}
void bfs2(){
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (indegree2[i] == 0){
			q.push(i);
		}
	}
	memset(possible, false, sizeof(possible));
	possible[d] = true;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = graph2[now].size();
		for (int i = 0; i < len; i++){
			int next = graph2[now][i].second;
			indegree2[next]--;
			if (indegree2[next] == 0){
				q.push(next);
			}
			if (possible[now] && dist[now] - dist[next] == graph2[now][i].first){
				possible[next] = true;
				ans++;
			}
		}
	}
}
int main(){
	cin >> n;
	graph1.resize(n + 1);
	graph2.resize(n + 1);
	cin >> m;
	while (m--){
		int u, v, x;
		cin >> u >> v >> x;
		graph1[u].push_back(make_pair(x, v));
		indegree1[v]++;
		graph2[v].push_back(make_pair(x, u));
		indegree2[u]++;
	}
	cin >> s >> d;
	bfs1();
	printf("%d\n", dist[d]);
	bfs2();
	printf("%d\n", ans);

}
