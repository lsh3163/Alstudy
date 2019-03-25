#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
//2차원 인접리스트
vector<vector<int> > graph;
//그냥 parent 배열, parent[i]에 i의 부모 노드값이 저장되어 있다.
vector<int> parent;
void makeparent(int root){
	vector<bool> visited;
	visited.resize(N + 1);
	queue<int> q;
	q.push(root);
	visited[root] = true;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		for (int next : graph[now]){
      // 다음 점으로 갈 때마다
			if (!visited[next]){
				visited[next] = true;
        // 다음점의 부모는 현재노드의 부모이므로 parent[next]=now
				parent[next] = now;
				q.push(next);
			}
		}
	}
}
int main(){
	cin >> N;
	graph.resize(N + 1);
	parent.resize(N + 1);
	for (int i = 1; i < N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	makeparent(1);
	for (int i = 2; i <= N; i++){
		printf("%d\n", parent[i]);
	}
}
