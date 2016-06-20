#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
//이차원 배열로 그래프 정의해서 풀기
//정점의 개수 1~1000
int N;
//간선의 개수 1~10000
int M;
//시작 정점
int V;
int graph[1234][1234];
//방문을 했는지 안헀는지 판정할 배열 visited선언
bool visited[1234];
void dfs(int n){
	//내 왔다라고 visited에 흔적 남기기
	visited[n] = true;
	//방문한 정점 출력
	printf("%d ", n);
	for (int i=1; i <= N; i++){
		//정점 i를 방문한 적이 없고 n->i로 가는 간선이 존재한다면
		if (!visited[i] && graph[n][i] == 1){
			//그 곳으로 ㄱㄱ씽
			dfs(i);
		}
	}
}
void bfs(int root){
	//root=V
	visited[root] = true;
	//bfs에 사용할 q선언
	queue<int> q;
	//처음 시작할 정점을 push해 줍니다.
	q.push(root);
	printf("%d ", root);
	//queue가 빌 때까지 탐색을 계속합니다.
	//queue가 빈다는 것은 더이상 방문할 정점이 없거나
	//해당 정점에서의 간선이 존재 하지 않는다는 뜻!
	while (!q.empty()){
		int next = q.front();
		q.pop();
		for (int i = 1; i <= N; i++){
			if (!visited[i] && graph[next][i] == 1){
				visited[i] = true;
				printf("%d ", i);
				q.push(i);
			}
		}
	}

}
int main(){
	cin >> N;
	cin >> M;
	cin >> V;
	for (int i = 0; i < M; i++){
		//간선이 연결되는 두 정점
		int u, v;
		cin >> u; cin >> v;
		//양방향이므로
		graph[u][v] = graph[v][u] = 1;
	}
	//방문한 적이 없다고 초기화
	for (int i = 1; i <= N; i++){
		visited[i] = false;
	}
	dfs(V);
	printf("\n");
	//방문한 적이 없다고 초기화
	for (int i = 1; i <= N; i++){
		visited[i] = false;
	}
	bfs(V);
}
