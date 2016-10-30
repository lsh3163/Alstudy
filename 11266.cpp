#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > graph;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;
int findCutVertex(int here, bool isRoot){
	discovered[here] = ++counter;
	int ret = discovered[here];
	int children = 0;
	int len = graph[here].size();
	for (int i = 0; i < len; i++){
		int next = graph[here][i];
		if (!discovered[next]){
			children++;
			int subtree = findCutVertex(next, false);
			if (!isRoot && subtree >= discovered[here]){
				isCutVertex[here] = true;
			}
			ret = min(ret, subtree);
		}
		else{
			ret = min(ret, discovered[next]);
		}
	}
	if (isRoot) isCutVertex[here] = (children >= 2);
	return ret;
}
int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n + 1);
	discovered.resize(n + 1);
	isCutVertex.resize(n + 1);
	for (int i = 1; i <= n; i++){
		discovered[i] = 0;
		isCutVertex[i] = false;
	}
	while (m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (discovered[i] == 0){
			findCutVertex(i, true);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (isCutVertex[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++){
		if (isCutVertex[i]){
			printf("%d ", i);
		}
	}
	return 0;
}
