#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
	int from;
	int to;
	int cost;
	bool operator < (const edge &other){
		return cost < other.cost;
	}
};
vector<edge> E;
int n,m;
int parent[10001];
int find(int x){
	if(x==parent[x]){
		return x;
	}
	return parent[x]=find(parent[x]);
}
void Union(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		parent[y]=x;
	}
}
int main()
{
	cin >> n >> m;
	E.resize(m);
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	for(int i=0;i<m;i++){
		cin >> E[i].from;
		cin >> E[i].to;
		cin >> E[i].cost;
	}
	sort(E.begin(),E.end());
	int ans=0;
	for(int i=0;i<m;i++){
		edge e = E[i];
		int start=find(e.from);
		int d=find(e.to);
		int cost=e.cost;
		if(start!=d){
			Union(start,d);
			ans+=cost;
		}
	}
	printf("%d",ans);
	return 0;
}
