#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int N, K;
bool visited[151];
vector<int> adj[151];
int bfs(int root) {
	visited[root] = true;
	queue<pair<int, int>> q;
	q.push({root, 0});
	while (!q.empty()) {
		int now = q.front().first;
		int d = q.front().second;
		q.pop();
		if (now == K) return d;
		for (int p : adj[now]) {
			if (!visited[p]) {
				q.push({ p, d + 1 });
				visited[p] = true;
			}
		}
	}
	return -1;
}
int main()
{
	cin >> N >> K;
	for(int n=0;n<N;n++){
		int v;
		cin >> v;
		adj[n].push_back(v);
	}
	printf("%d", bfs(0));
}
