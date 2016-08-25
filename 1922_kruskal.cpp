#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int cost;
    //edge 자료형 의 크다를 정의
	bool operator < (const edge &other){
		return cost < other.cost;
	}
};
vector<edge> group;
int parent[1001];
//경로 압축
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
	group.resize(m);
	for(int i=0;i<m;i++){
		cin >> group[i].from;
		cin >> group[i].to;
		cin >> group[i].cost;
	}
	for(int i=1;i<=n;i++){
		parent[i]=i;
	}
	sort(group.begin(),group.end());
	int ans=0;
	for(int i=0;i<m;i++){
		int x=find(group[i].from);
		int y=find(group[i].to);
		if(x!=y){
			Union(x,y);
			ans+=group[i].cost;
		}
	}
	printf("%d",ans);
	return 0;
}
