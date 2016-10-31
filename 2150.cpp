#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int n, m;
// 그래프의 인접 리스트 표현
vector<vector<int> > adj;

// 각 정점의 컴포넌트 번호. 컴포넌트 번호는 0 부터 시작하며, 
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;

// 각 정점의 발견 순서와 scc() 종료 여부
vector<int> discovered, finished;

// 정점의 번호를 담는 스택
stack<int> st;

int sccCounter, vertexCounter;

// here 를 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소의 발견 순서를
// 반환한다.
int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	// 스택에 here 를 넣는다. here 의 후손들은 모두 스택에서 here 후에 들어간다.
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		// (here,there) 가 트리 간선
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		// (here,there) 가 역방향이나 교차 간선
		else if (discovered[there] < discovered[here] && sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	// here 가 강결합 컴포넌트의 루트인가 확인한다
	if (ret == discovered[here]) {
		// here 를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
	}
	finished[here] = 1;
	return ret;
}

// tarjan 의 SCC 알고리즘
vector<int> tarjanSCC() {
	// 배열들을 전부 초기화
	sccId = discovered = vector<int>(n + 1, -1);
	finished = vector<int>(n + 1, 0);
	// 카운터 초기화
	sccCounter = vertexCounter = 0;
	// 모든 정점에 대해 scc() 호출
	for (int i = 1; i <= n; i++) if (discovered[i] == -1) scc(i);
	return sccId;
}
bool cmp(const vector<int> &a, const vector<int> &b){
	return a[0] < b[0];
}
int main(){
	cin >> n >> m;
	adj.resize(n + 1);
	while (m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	vector<int> res = tarjanSCC();
	vector<vector<int> > print = vector<vector<int> >(sccCounter,vector<int>());
	for (int i = 1; i <= n; i++){
		print[res[i]].push_back(i);
	}
	sort(print.begin(), print.end(), cmp);
	printf("%d\n", sccCounter);
	for (auto connected : print){
		for (auto node : connected){
			printf("%d ", node);
		}
		printf("-1\n");
	}
	return 0;
}
