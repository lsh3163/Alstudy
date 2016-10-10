#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int T, W;
int postable[1002];
int memo[3][1001][31];
int solve(int pos, int time,int w){
	if (w > W){
		return 0;
	}
	if (time == T + 1){
		return 0;
	}
	int &ret = memo[pos][time][w];
	if (ret != -1){
		return ret;
	}
	ret = 0;
	int nextpos = (pos) % 2 + 1;
	//움직이는 경우
	if (postable[time] == pos){
		ret = max(ret, solve(nextpos, time + 1, w + 1) + 1);
	}
	else{
		ret = max(ret, solve(nextpos, time + 1, w + 1));
	}
	//안 움직이는 경우
	if (postable[time] == pos){
		ret = max(ret, solve(pos, time + 1, w) + 1);
	}
	else{
		ret = max(ret, solve(pos, time + 1, w));
	}
	return ret;
}
int main(){
	cin >> T >> W;
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= T; i++){
		cin >> postable[i];
	}
	printf("%d\n", max(solve(1, 1, 0), solve(2, 1, 0)));
	return 0;
}
