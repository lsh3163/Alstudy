#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<vector<int>> v;
int check[2002];
int flag;

void dfs(int now, int d) {
  // 깊이가 4일 때 함수 종료
	if (d == 4) {
		flag = 1;
		return;
	}
	check[now] = 1;
	for (int next : v[now]) {
		if (check[next] == 0) {
			 dfs(next, d + 1);
		}
		if (flag == 1) return;
	}
  // 현재 점을 다시 0으로 바꿔준다.
	check[now] = 0;
}
int main(void) {
	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < m; i++) {
		int u, w;
		cin >> u >> w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
    //flag가 1이면 이미 찾았으므로 break
		if (flag == 1) break;
		memset(check, 0, sizeof(check));
	}
	if(flag==0){
		printf("0\n");
	}
	else{
		printf("1\n");
	}
	return 0;
}

