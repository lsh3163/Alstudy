#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int n;
vector<vector<int> > graph;
vector<int> work;
vector<int> d;
vector<int> indgree;
void bfs(){
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (indgree[i] == 0){
			q.push(i);
            //선행 조건이 없으면
            //i하는데 걸리는 시간은 work[i]
			d[i] = work[i];
		}
	}
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i];
			indgree[next]--;
            //오래 밥 먹는 애들 기준
			if (d[next] < d[now] + work[next]){
				d[next] = d[now] + work[next];
			}
			if (indgree[next] == 0){
				q.push(next);
			}
		}
	}
}
int main(){
	cin >> n;
	graph.resize(n + 1);
	work.resize(n + 1);
	d.resize(n + 1);
	indgree.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> work[i];
		int cnt;
		cin >> cnt;
		while (cnt--){
			int point;
			cin >> point;
			graph[point].push_back(i);
			indgree[i]++;
		}
	}
	bfs();
	int answer = 0;
	for (int i = 1; i <= n; i++){
		answer = max(answer, d[i]);
	}
	printf("%d", answer);
}
