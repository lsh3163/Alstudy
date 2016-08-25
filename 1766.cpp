#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
vector<vector<int> > graph;
int indegree[32001];
void Topo(){
    //번호 순이 작은 것이 우선순위를 가지므로
    //min heap
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now=q.top();
		printf("%d ",now);
		q.pop();
		int len=graph[now].size();
		for(int i=0;i<len;i++){
			int next=graph[now][i];
			indegree[next]--;
			if(indegree[next]==0){
				q.push(next);
			}
		}
	}
}
int main()
{
	cin >> n; cin >> m;
	graph.resize( n + 1 );
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}
	Topo();
	return 0;
}
