#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
bool visited[10001];
//first에 어디로부터 왔는지
//second에 알파벳 D,S,L,R
char how[10001];
int from[10001];
//초기 값, 최종 값
int A, B;
void bfs(int root){
	visited[root] = true;
	queue<int> q;
	q.push(root);
	from[root] = -1;
	how[root] = 'B';
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int next;
		//D인 경우
		next = (now * 2) % 10000;
		if (!visited[next]){
			visited[next] = true;
			q.push(next);
			from[next] = now;
			how[next] = 'D';
		}
		//S인 경우
		next = (now - 1);
		if (next < 0){
			next = 9999;
		}
		if (!visited[next]){
			visited[next] = true;
			q.push(next);
			from[next] = now;
			how[next] = 'S';
		}
		//L인 경우
		next = (now % 1000) * 10 + (now / 1000);
		if (!visited[next]){
			visited[next] = true;
			q.push(next);
			from[next] = now;
			how[next] = 'L';
		}
		//R인 경우
		next = (now % 10) * 1000 + (now / 10);
		if (!visited[next]){
			visited[next] = true;
			q.push(next);
			from[next] = now;
			how[next] = 'R';
		}
	}
}
int main(){
	int T;
	cin >> T;
	while (T--){
		memset(visited, false, sizeof(visited));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		cin >> A; cin >> B;
		bfs(A);
		string answer = "";
		while (B != A){
			answer += how[B];
			B = from[B];
		}
		reverse(answer.begin(), answer.end());
		int len = answer.length();
		for (int i = 0; i < len; i++){
			printf("%c", answer[i]);
		}
		printf("\n");
	}
}
