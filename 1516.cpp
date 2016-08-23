#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<vector<int> > graph;
vector<int> buildt;
vector<int> d;
vector<int> indegree;
void bfs(){
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (indegree[i] == 0){
			q.push(i);
		}
		d[i] = buildt[i];
	}
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i];
			indegree[next]--;
			if (indegree[next] == 0){
				q.push(next);
			}
			if (d[next] < d[now] + buildt[next]){
				d[next] = d[now] + buildt[next];
			}
		}
	}
}
int main(){
	cin >> n;
	graph.resize(n + 1);
	buildt.resize(n + 1);
	d.resize(n + 1);
	indegree.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> buildt[i];
		while (true){
			int x;
			cin >> x;
			if (x == -1){
				break;
			}
			graph[x].push_back(i);
			indegree[i]++;
		}
	}
	bfs();
	for (int i = 1; i <= n; i++){
		printf("%d\n", d[i]);
	}
}
