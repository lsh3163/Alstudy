#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int A, P;
int visited[1231231];
int bfs(int root){
	int cnt = 1;
	visited[root] = cnt;
	//숫자,횟수
	queue<pair<int, int> > q;
	q.push(make_pair(root, cnt));
	while (!q.empty()){
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		int n = now;
		int next = 0;
		while (n > 0){
			int a = n % 10;
			int b = 1;
			for (int i = 0; i < P; i++){
				b *= a;
			}
			next += b;
			n /= 10;
		}
		if (visited[next] == 0){
			visited[next] = count + 1;
			q.push(make_pair(next, count + 1));
		}
		else if (visited[next] > 0){
			return visited[next] - 1;
		}
	}
}
int main(void){
	cin >> A; cin >> P;
	int answer = bfs(A);
	printf("%d", answer);
}
