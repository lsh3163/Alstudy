#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int Firstdoor;
int Seconddoor;
int memo[30][30][30];
vector<int> doornum;
int solve(int n, int fdoor, int sdoor){
	if (n == N){
		return 0;
	}
	int &ret = memo[n][fdoor][sdoor];
	if (ret != -1){
		return ret;
	}
	//to fdoor or to sdoor
	ret = min(solve(n + 1, doornum[n], sdoor) + abs(doornum[n] - fdoor), solve(n + 1, fdoor, doornum[n]) + abs(doornum[n] - sdoor));
	return ret;
}
int main(){
	cin >> N;
	cin >> Firstdoor; cin >> Seconddoor;
	cin >> N;
	doornum.resize(N);
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < N; i++){
		cin >> doornum[i];
	}
	int answer = solve(0, Firstdoor, Seconddoor);
	printf("%d", answer);
}
