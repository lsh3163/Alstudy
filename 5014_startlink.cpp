#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
#define SIZE 1000002
using namespace std;
int F, S, G, U, D;
bool visited[SIZE];
int bfs(int s, int g){
	queue<pair<int,int > > q;
	q.push(make_pair(s, 0));
	memset(visited, false, SIZE);
	while (!q.empty()){
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		if (now == g){
			return count;
		}
		if (now + U <= F){
			if (!visited[now + U]){
				visited[now + U] = true;
				q.push(make_pair(now + U, count + 1));
			}
		}
		if (now - D >= 1){
			if (!visited[now - D]){
				visited[now - D] = true;
				q.push(make_pair(now - D, count + 1));
			}
		}
	}
	return -1;
}
int main(){
	cin >> F; 
	cin >> S; cin >> G; 
	cin >> U; cin >> D;
	int answer = bfs(S, G);
	if (answer == -1){
		printf("use the stairs");
	}
	else{
		printf("%d", answer);
	}
}
