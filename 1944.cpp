#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct edge{
	int x;
	int y;
	int cost;
	bool operator < (const edge &other){
		return cost < other.cost;
	}
};
struct point{
	int x;
	int y;
};
int dist[51][51];
int N;
int M;
int number[51][51];
char board[51][51];
vector<int> parent;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<edge> group;
int bfs(int rx, int ry){
	queue<point> q;
	memset(dist, -1, sizeof(dist));
	q.push({ rx, ry });
	dist[rx][ry] = 0;
	while (!q.empty()){
		int nowx = q.front().x;
		int nowy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];
			if (nextx >= 1 && nextx <= N && nexty >= 1 && nexty <= N){
				if (board[nextx][nexty] != '1'){
					if (dist[nextx][nexty] == -1 || dist[nextx][nexty]>dist[nowx][nowy] + 1){
						dist[nextx][nexty] = dist[nowx][nowy] + 1;
						q.push({ nextx, nexty });
						if (board[nextx][nexty] == 'S' || board[nextx][nexty] == 'K'){
							group.push_back({ number[rx][ry], number[nextx][nexty], dist[nextx][nexty] });
						}
					}
				}
			}
		}
	}
	return 0;
}
int find(int x){
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void merge(int u, int v){
	u = find(u);
	v = find(v);
	if (u != v){
		parent[u] = v;
	}
}
int main(){
	cin >> N >> M;
	vector<point> p;
	int cnt = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			char c;
			cin >> c;
			board[i][j] = c;
			if (c == 'S' || c == 'K'){
				p.push_back({ i, j });
				number[i][j] = cnt;
				cnt++;
			}
		}
	}
	parent.resize(cnt + 1);
	int size = p.size();
	for (int i = 0; i < size; i++){
		int x = bfs(p[i].x, p[i].y);
	}
	int n = group.size();
	sort(group.begin(), group.end());
	for (int i = 1; i <= cnt; i++){
		parent[i] = i;
	}
	int answer = 0;
	int check = 0;
	for (int i = 0; i < n; i++){
		int from = group[i].x;
		int to = group[i].y;
		int f = find(from);
		int t = find(to);
		if (f != t){
			merge(f, t);
			answer += group[i].cost;
			check++;
		}
	}
	if(check==(size-1))printf("%d", answer);
	else printf("-1");
	
}
