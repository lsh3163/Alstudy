#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int> > lx;
vector<pair<int, int> > ly;
vector<pair<int, int> > lz;
int N;
vector<vector<pair<int, int>>> graph;
long long prim(int root){
	priority_queue<pair<int, int> > q;
	vector<bool> visited;
	visited.resize(N + 1);
	q.push(make_pair(0, root));
	long long ans = 0;
	while (!q.empty()){
		int now = q.top().second;
		int nowcost = -q.top().first;
		q.pop();
		if (visited[now]) continue;
		visited[now] = true;
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].first;
			int nextcost = graph[now][i].second;
			if (!visited[next]){
				q.push(make_pair(-nextcost, next));
			}
		}
		ans += nowcost;
	}
	return ans;
}
int main(){
	cin >> N;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		lx.push_back(make_pair(x, i));
		ly.push_back(make_pair(y, i));
		lz.push_back(make_pair(z, i));
	}
	sort(lx.begin(), lx.end());
	sort(ly.begin(), ly.end());
	sort(lz.begin(), lz.end());
	
	for (int i = 0; i<N - 1; i++){
		graph[lx[i].second].push_back(make_pair(lx[i + 1].second, lx[i + 1].first - lx[i].first));
		graph[lx[i + 1].second].push_back(make_pair(lx[i].second, lx[i + 1].first - lx[i].first));
		graph[ly[i].second].push_back(make_pair(ly[i + 1].second, ly[i + 1].first - ly[i].first));
		graph[ly[i + 1].second].push_back(make_pair(ly[i].second, ly[i + 1].first - ly[i].first));
		graph[lz[i].second].push_back(make_pair(lz[i + 1].second, lz[i + 1].first - lz[i].first));
		graph[lz[i + 1].second].push_back(make_pair(lz[i].second, lz[i + 1].first - lz[i].first));
	}
	printf("%lld\n", prim(1));
}
