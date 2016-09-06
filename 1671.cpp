#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
struct point{
	int big;
	int velocity;
	int brain;
	bool operator <= (const point &other){
		return big <= other.big && velocity <= other.velocity && brain <= other.brain;
	}
	bool operator == (const point &other){
		return big == other.big && velocity == other.velocity && brain == other.brain;
	}
};
vector<point> v;
vector<vector<int> > graph;
vector<int> pred;
vector<bool> visited;
bool dfs(int x){
	if (x == -1){
		return true;
	}
	for (int next : graph[x]){
		if (visited[next]) continue;
		visited[next] = true;
		if (dfs(pred[next])){
			pred[next] = x;
			return true;
		}
	}
	return false;
}
int main(){
	cin >> n;
	v.resize(n + 1);
	graph.resize(n + 1);
	visited.resize(n + 1);
	pred.resize(n + 1, -1);
	for (int i = 1; i <= n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = { a, b, c };
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j) continue;
			if (v[i] == v[j]){
				if (i < j){
					graph[j].push_back(i);
				}
			}
			else if (v[i] <= v[j]){
				graph[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++){
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)){
				ans++;
			}
		}
	}
	printf("%d", n - ans);
}
