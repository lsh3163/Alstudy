#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
vector<vector<int > > graph;
bool visited[1001];
void dfs(int n){
	visited[n] = true;
	int len = graph[n].size();
	for (int i = 0; i < len; i++){
		int there = graph[n][i];
		if (!visited[there]){
			dfs(there);
		}
	}
}
int main(void){
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		memset(visited, false, sizeof(visited));
		graph.clear();
		graph.resize(N + 1);
		for (int i = 1; i <= N; i++){
			int input;
			cin >> input;
			graph[i].push_back(input);
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++){
			if (!visited[i]){
				cnt++;
				dfs(i);
			}
		}
		printf("%d\n", cnt);
	}
}
