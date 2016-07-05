#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int> v;
int memo[12312][3];
int solve(int idx, int check){
	if (idx >= N){
		return 0;
	}
	int &ret = memo[idx][check];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	if (check == 2){
		//무조건 선택을 안 해야함
		ret = solve(idx + 1, 0);
	}
	else if (check == 0 || check == 1){
		// 선택한 경우와 안 한 경우
		ret = max(solve(idx + 1, check + 1) + v[idx], solve(idx + 1, 0));
	}
	return ret;
}
int main(){
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++){
		cin >> v[i];
		for (int j = 0; j < 3; j++){
			memo[i][j] = -1;
		}
	}
	int answer = solve(0, 0);
	printf("%d", answer);
}
