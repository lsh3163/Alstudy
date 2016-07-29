#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
long long M;
vector<long long> group;
bool decision(long long k){
	int len = group.size();
	long long check = 0;
	for (int i = 0; i < len; i++){
		if (group[i] > k){
			check += (group[i] - k);
		}
	}
	return check >= M;
}
long long optimize(){
	//0부터 longlong에 있는 모든 수를 우선 정답후보로 봄
	long long low = 0;
	long long high = LLONG_MAX;
	long long mid;
	//100번만 돌려도 무한루프 안돌고 2의 100승만큼 탐색가능
	for (int i = 0; i < 100; i++){
		mid = (low + high) / 2;
		if (decision(mid)){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return low;
}
int main(void){
	cin >> N; cin >> M;
	group.resize(N);
	for (int i = 0; i < N; i++){
		cin >> group[i];
	}
	printf("%lld", optimize());
}
