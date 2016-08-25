#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > adj;
int n,m;
int indgree[32001];
void TopologicalSort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
	  //선행 조건이 없으면
		if(indgree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now=q.front();
		printf("%d ",now);
		q.pop();
		int len=adj[now].size();
		for(int i=0;i<len;i++){
		  //선행 조건을 없애다가
		  //0이되면 큐이 넣음
		  //즉 큐에는 선행 조건이 0인 것만 들어감
			int next=adj[now][i];
			indgree[next]--;
			if(indgree[next]==0){
				q.push(next);
			}
		}
	}
}
int main(void){
	cin >> n;cin >> m;
	adj.resize(n+1);
	while(m--){
		int u,v;
		cin >> u;cin >>v;
		//u=>v를 갈 수 있다.
		adj[u].push_back(v);
		indgree[v]++;
	}
	TopologicalSort();
	return 0;
}
