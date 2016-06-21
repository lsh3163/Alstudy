#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
//pair이용해서 풀기
//visited배열 선언->방문했는지 안헀는지
bool visited[123123];
int bfs(int root,int destination){
	visited[root] = true;
	//좌표와 시간을 저장할 queue 선언
	queue<pair<int,int > > q;
	//처음 수빈이가 있는 위치와 시간을 push
	q.push(make_pair(root, 0));
	//그 점에서 방문할 수 없는 점이 없을 때까지 탐색 계속==queue가 빌 때까지 돌림
	while (!q.empty()){
		//queue의 front의 현재 좌표값과 시간값을 가져옴
		int now = q.front().first;
		int time = q.front().second;
		//pop을 시켜줘야 무한루프가 안남
		q.pop();
		//현재 좌표가 도착지랑 같다면 time을 return==answer
		if (destination == now){
			return time;
		}
		//가고자 하는 점이 범위 안에 있고 방문한 적이 없다면
		//방문했다고 기록을 남겨주고 이게 다음 갈 정점이라는 것==queue에 push
		if (now + 1 <= 100000 && now + 1 >= 0){
			if (!visited[now + 1]) { 
				visited[now + 1] = true;
				q.push(make_pair(now + 1, time + 1)); 
			}
		}
		if (now - 1 <= 100000 && now - 1 >= 0){
			if (!visited[now - 1]) {
				visited[now - 1] = true;
				q.push(make_pair(now - 1, time + 1));
			}
		}
		if (now * 2 <= 100000 && now * 2 >= 0){
			if (!visited[now * 2]) {
				visited[now * 2] = true;
				q.push(make_pair(now * 2, time + 1));
			}
		}

	}
}
int main(){
	//수빈이가 있는 위치 N과 동생이 있는 위치 K선언
	int N, K;
	cin >> N;
	cin >> K;
	for (int i = 0; i < 123123; i++){
		visited[i] = false;
	}
	int answer = bfs(N, K);
	printf("%d", answer);
}
