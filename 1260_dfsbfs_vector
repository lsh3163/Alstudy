#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//2차원 벡터로 정점간의 정보로 나타내고 dfs와 bfs로 탐색하기
//간선간의 정보를 담을 2차원 벡터 vec 정의
vector<vector<int> > vec;
//정점의 개수
int N;
//간선의 개수
int M;
//방문 했는지 안 했는지 저장할 bool 형의 배열 visited 선언
bool visited[1234];
//dfs 함수의 기능: n행에 대하여 연결된 정점을 돌면서 
//그 정점에 대하여 또다시 재귀로 탐색 
void dfs(int n){
	//정점 n을 돈적이 있음=>true
	visited[n] = true;
	printf("%d ", n);
	//n행에 정점을 보면서 탐색한 적이 없다면 
	//다음 정점으로 dfs(i)로 들어감
	for (vector<int>::size_type i = 0; i < vec[n].size(); i++){
		if (!visited[vec[n][i]]){
			dfs(vec[n][i]);
		}
	}
}
//n정점에 대하여 연결되어있는 점을 방문한 적이 없다면
//전부 push
void bfs(int n){
	visited[n] = true;
	queue<int> q;
	q.push(n);
	//q가 빌 때까지 탐색
	while (!q.empty()){
		int now = q.front();
		printf("%d ", now);
		q.pop();
		//정점에 연결되어있고 방문한 적이 없다면 계속 push
		for (vector<int>::size_type i = 0; i < vec[now].size(); i++){
			if (!visited[vec[now][i]]){
				visited[vec[now][i]] = true;
				q.push(vec[now][i]);
			}
		}
	}
}
int main(){
	//시작할 정점 번호 V
	int V;
	cin >> N;
	//2차원 벡터를 전역영역에서 선언만 하였으므로 
	//resize함수로써 행개수 지정
	vec.resize(N + 1);
	cin >> M;
	cin >> V;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u;
		cin >> v;
		//양방향이므로 u행에 v를 push
		//v행에 u를 push
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	//정렬해야됨=>문제에서 여러개로 연결되어 있다면
	//가장 작은 수부터 탐색하라고 하였으므로
	for (int i = 1; i <= N; i++){
		sort(vec[i].begin(), vec[i].end());
	}
	//visited를 false라 하면서 초기화=>정점방문한적 없음!
	for (int i = 1; i <= 1234; i++){
		visited[i] = false;
	}
	dfs(V);
	//마찬가지
	for (int i = 1; i <= 1234; i++){
		visited[i] = false;
	}
	printf("\n");
	bfs(V);
}
