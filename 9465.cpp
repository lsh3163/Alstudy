#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int T;
//2행 N열 
int N;
vector<pair<int, int> > score;
int memo[100001][3];
//해당 index까지의 점수 최대값을 구함
//check==해당 index에서 선택가능한 수
int solve(int index, int check){
	if (index > N){
		return 0;
	}
	int &ret = memo[index][check];
	if (ret != -1){
		return ret;
	}
	ret = 0;

	int first = score[index].first;
	int second = score[index].second;
	//선택 X
	ret = solve(index + 1, 0);
	//check==0일 경우 index에서 선택 x
	//index + 1에서 first,second,X선택가능
	if (check == 0){
		ret = max(solve(index + 1, 2) + first, ret);
		ret = max(solve(index + 1, 1) + second, ret);
	}
	//check==1일 경우 index에서 first 선택 
	//index + 1에서 second 혹은 X
	if (check == 1){
		ret = max(ret, solve(index + 1, 2) + first);
	}
	//check==2일 경우 index에서 second선택
	//index + 1에서 first 혹은 X
	if (check == 2){
		ret = max(ret, solve(index + 1, 1) + second);
	}
	return ret;
}
int main(void){
	cin >> T;
	while (T--){
		scanf("%d",&N);
		//T에 따른 벡터 초기화
		score.clear();

		//1~N열 사용
		score.resize(N + 1);
		for (int i = 1; i <= N; i++){
			scanf("%d",&score[i].first);
		}
		memo[0][0] = memo[0][1] = memo[0][2] = -1;
		for (int i = 1; i <= N; i++){
			scanf("%d",&score[i].second);
			for (int j = 0; j < 3; j++){
				memo[i][j] = -1;
			}
		}
		int answer = solve(0, 0);
		printf("%d\n", answer);
	}
}
