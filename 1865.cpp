#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
struct point{
	int from;
	int to;
	int cost;
};
int n, m, w;
const int inf = 0x1fffffff;
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> n; cin >> m; cin >> w;
		vector<point> group;
		int dist[501];
		for (int i = 1; i <= n; i++){
			dist[i] = inf;
		}
		for (int i = 0; i < m; i++){
			int u, v, x;
			cin >> u >> v >> x;
			group.push_back({ u, v, x });
			group.push_back({ v, u, x });
		}
		for (int i = 0; i < w; i++){
			int u, v, x;
			cin >> u >> v >> x;
			group.push_back({ u, v, -x });
		}
		dist[1] = 0;
		bool negative = false;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < (m*2 + w); j++){
				int x = group[j].from;
				int y = group[j].to;
				int z = group[j].cost;
				if (dist[x] != inf && dist[y]>dist[x] + z){
					dist[y] = dist[x] + z;
					if (i == n){
						negative = true;
					}
				}
			}
		}
		if (negative){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
