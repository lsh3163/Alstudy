#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> Group;
bool decision(int Child){
	int Check = 0;
	for (int i = 0; i < M; i++){
		if (Group[i] % Child == 0){
			Check += (Group[i] / Child);
		}
		else{
			Check += (Group[i] / Child) + 1;
		}
	}
	return N >= Check;
}
int optimize(){
	int low = 1;
	int high = 1000000000;
	int mid;
	for (int i = 0; i < 100; i++){
		mid = (low + high) / 2;
		if (decision(mid)){
			high = mid;
		}
		else{
			low = mid;
		}
	}
	return high;
}
int main(void){
	cin >> N; cin >> M;
	Group.resize(M);
	for (int i = 0; i < M; i++){
		cin >> Group[i];
	}
	printf("%d", optimize());
}
