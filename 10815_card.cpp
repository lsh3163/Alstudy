#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> group;
vector<int> ans;
int optimize(int tar){
	//low와 high는 인덱스로써 최소 최대가 0, N - 1
	int low = 0;
	int high = N - 1;
	int mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (group[mid] == tar){
			//목표한 값을 찾으면 1을 return
			return 1;
		}
		else if (group[mid] > tar){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	//못 찾으면 0을 return
	return 0;
}
int main(void){
	cin >> N;
	group.resize(N);
	for (int i = 0; i < N; i++){
		cin >> group[i];
	}
	sort(group.begin(), group.end());
	cin >> M;
	for (int i = 0; i < M; i++){
		int target;
		cin >> target;
		ans.push_back(optimize(target));
	}
	int len = ans.size();
	for (int i = 0; i < len; i++){
		printf("%d ", ans[i]);
	}
}

