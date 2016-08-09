#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int M;
int memo[2001][2001];
vector<int> num;
int solve(int start, int end){
	if (start == end){
		return 1;
	}
	if ((end - start) == 1){
		if (num[start] == num[end]){
			return 1;
		}
		return 0;
	}
	int &ret = memo[start][end];
	if (ret != -1){
		return ret;
	}
	if (num[start] == num[end]){
		ret = solve(start + 1, end - 1);
	}
	if (num[start] != num[end]){
		return 0;
	}
	return ret;
}
int main() {
	
	cin >> N;
	num.resize(N + 1);
	for (int i = 1; i <= N; i++){
		cin >> num[i];
		for (int j = 1; j <= N; j++){
			memo[i][j] = -1;
		}
	}
	cin >> M;
	while (M--){
		int u, v;
		scanf("%d %d",&u,&v);
		printf("%d\n", solve(u, v));
	}
}
