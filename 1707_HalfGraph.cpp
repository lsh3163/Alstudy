#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int V, E;
vector<vector<int > > graph;
int bi[21212]; // -1아직 노방문, 0파란색, 1빨간색
bool bfs(int root){
	bi[root] = 0;
	queue<int> q;
	q.push(root);
	while (!q.empty()){
		int n = q.front();
		q.pop();
		int dir = bi[n];
		int ndir = !dir;
		int len = graph[n].size();
		for (int i = 0; i < len; i++){
			if (bi[graph[n][i]] == -1){
				bi[graph[n][i]] = ndir;
				q.push(graph[n][i]);
			}
			else if (bi[graph[n][i]] == dir){
				return false;
			}
			
		}
	
	}
	return true;

}
int main(){
	int T;
	cin >> T;
	while (T--){
		int V, E;
		cin >> V;
		cin >> E;
		graph.clear();
		graph.resize(V + 1);
		for (int i = 1; i <= V; i++){
			graph[i].clear();
		}
		for (int i = 0; i < E; i++){
			int u, v;
			cin >> u; cin >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(bi, -1, (V + 1));
		bool res = true;
		for (int i = 1; i <= V; i++){
			if (bi[i] == -1){
				res &= bfs(i);
			}
		}
		if (res){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	
	}

}
