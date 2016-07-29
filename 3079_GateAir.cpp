#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int N;
long long M;
vector<long long> group;
bool decision(long long time){
	long long check = 0;
	int len = group.size();
	for (int i = 0; i < len; i++){
		check += (time / group[i]);
	}
	return M > check;
}
long long optimize(){
	long long low = 0;
	long long high = 987654321987654LL;
	long long mid;
	for (int i = 0; i < 100; i++){
		mid = (low + high) / 2;
		if (decision(mid)){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return high;
}
int main(void){
	cin >> N; cin >> M;
	group.resize(N);
	for (int i = 0; i < N; i++){
		cin >> group[i];
	}
	printf("%lld", optimize());
}
