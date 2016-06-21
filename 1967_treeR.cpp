#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<pair<int, int > > > graph;
bool visited[12345];
pair<int, int>furthest(int root){
	//방문 한적이 없다=false로 visited 초기화
	memset(visited, false, 12345);
	//경로 탐색에 필요할 queue선언 first는 해당 정점
	//second는 거리
	queue<pair<int, int > > q;
	visited[root] = true;
	//처음 정점은 root 이며 거리는 0
	q.push(make_pair(root, 0));
	//return 할 pair ret선언
	pair<int, int > ret;
	//-1로 초기화
	ret.first = -1;
	ret.second = -1;
	//한 정점에서 더이상 방문할 정점이 없을 때까지 탐색
	//==
	//queue가 빌 때까지 탐색
	while (!q.empty()){
		//queue의 front로 부터 정점과 거리를 불러옴
		int now = q.front().first;
		int dis = q.front().second;
		int len = graph[now].size();
		q.pop();
		//한 정점에서 갈 수 있는 정점을 for문에서 탐색
		for (int i = 0; i < len; i++){
			if (!visited[graph[now][i].first]){
				//방문한 적이 없다면 true라고 해줌
				//벡터를 이용해서 graph를 만들었을 때
				//이 if문을 타고 들어왔다면 now->i의 간선이 무조건 있음
				visited[graph[now][i].first] = true;
				//queue에 다음 정점과 거리를 pair형식으로 push해줌
				q.push(make_pair(graph[now][i].first, dis + graph[now][i].second));
				//최신 거리가 원래 묵혀놨던 거리보다 크면
				if (dis + graph[now][i].second>ret.second){
					//return 할 pair ret에 새로 갱신
					ret.first = graph[now][i].first;
					ret.second = dis + graph[now][i].second;
				}
			}
		}
	
	}
	return ret;
}
int main(){
	int n;
	cin >> n;
	graph.resize(n + 1);
	//2번째 줄부터 n줄이므로 1을 빼줌
	n--;
	//while문 돌면서 그래프에 u,v,x=>간선이 양방향이므로 v,u,x도 저장해줘야함
	while (n--){
		int u, v, x;
		cin >> u; cin >> v; cin >> x;
		graph[u].push_back(make_pair(v, x));
		graph[v].push_back(make_pair(u, x));
	}
	//1에서 가장 멀리있는 점을 찾은 후
	pair<int, int > first = furthest(1);
	//그 점에서 가장 멀리있는 점과 그 거리를 answer에 저장
	//이 때 answer.first는 1이 아니다
	//그 이유는 1에서 가장 먼 점이 first.first에서 가장 먼 점이 아니다
	pair<int, int > answer = furthest(first.first);
	//first.first에서 가장 먼 거리를 출력
	printf("%d", answer.second);
}
