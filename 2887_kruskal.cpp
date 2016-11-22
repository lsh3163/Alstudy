#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,int> > lx;
vector<pair<int,int> > ly;
vector<pair<int,int> > lz;
int N;
struct edge{
	int x, y, z;
	edge() {}
	edge(int a,int b,int c){
		x = a;
		y = b;
		z = c;
	}
};
vector<edge> group;
vector<int> parent;
bool cmp(edge &a,edge &b){
	if(a.z==b.z){
		return a.x > b.x;
	}
	return a.z < b.z;
}
int find(int x)
{
	if(x==parent[x]){
		return x;
	}
	return parent[x] = find(parent[x]);
}
void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x!=y){
		parent[x] = y;
	}
}
long long kruskal(){
	long long res = 0;
	sort(group.begin(),group.end(),cmp);
	parent.resize(N+1);
	for(int i=1;i<=N;i++){
		parent[i] = i;
	}
	int len = group.size();
	for (int i = 0; i < 3*N-3; i++)
    {
        int x = group[i].x;
        int y = group[i].y;
        int r1 = find(x);
        int r2 = find(y);
        //해당 간선 추가.
        if (r1 != r2)
        {
            merge(x, y);
            res += group[i].z;
        }
    }
	return res;
}
int main(){
	cin >> N;
	for(int i = 1;i <= N;i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		lx.push_back(make_pair(x,i));
		ly.push_back(make_pair(y,i));
		lz.push_back(make_pair(z,i));
	}
	sort(lx.begin(),lx.end());
	sort(ly.begin(),ly.end());
	sort(lz.begin(),lz.end());
	for(int i=0; i<N-1; i++){
		group.push_back(edge(lx[i].second,lx[i+1].second,lx[i+1].first-lx[i].first));
		group.push_back(edge(ly[i].second,ly[i+1].second,ly[i+1].first-ly[i].first));
		group.push_back(edge(lz[i].second,lz[i+1].second,lz[i+1].first-lz[i].first));
	}
	printf("%lld\n",kruskal());
}
