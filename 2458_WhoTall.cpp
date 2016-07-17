#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
bool visited[501];
bool r_visited[501];
vector<vector<int> > graph1;
vector<vector<int> > graph2;
void dfs1(int n){
	visited[n] = true;
	int len = graph1[n].size();
	for (int i = 0; i < len; i++){
		int there = graph1[n][i];
		if (!visited[there]){
			dfs1(there);
		}
	}
}
void dfs2(int n){
	r_visited[n] = true;
	int len = graph2[n].size();
	for (int i = 0; i < len; i++){
		int there = graph2[n][i];
		if (!r_visited[there]){
			dfs2(there);
		}
	}
}
int main(void){
	cin >> N; cin >> M;
	graph1.resize(N + 1);
	graph2.resize(N + 1);
	while (M--){
		int u, v;
		cin >> u; cin >> v;
		graph1[u].push_back(v);
		graph2[v].push_back(u);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++){
		memset(visited, false, sizeof(visited));
		memset(r_visited, false, sizeof(visited));
		dfs1(i);
		dfs2(i);
		int check = 0;
		for (int j = 1; j <= N; j++){
			if (visited[j] || r_visited[j]){
				check++;
			}
		}
		if (check == N){
			answer++;
		}
	}
	printf("%d", answer);
}
