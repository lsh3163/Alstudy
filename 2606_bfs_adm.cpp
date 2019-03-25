#include <iostream>
#include <queue>
using namespace std;

int V, E;
int graph[101][101];
bool visited[101];

void bfs(int root){
	queue<int> q;
	q.push(root);
	visited[root] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=1;i<=V;i++){
			if(graph[now][i]==1 && !visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	// V, E -> 정점의 개수와 간선의 개수
	cin >> V >> E;
	while(E--){
		int u, v;
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	bfs(1);
	//1번에서 방문을 시작했을 때, 방문된 점의 개수
	int ans=0;
	for(int i=1;i<=V;i++){
		if(visited[i]) ans++;
	}
	//1번은 출발점이므로 제외
	printf("%d", ans-1);
	return 0;
}
