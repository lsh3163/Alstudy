#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
vector<int> v;
int N, S;
int answer = 0;
bool selected[30];
void solve(int index,int sum){
	if (index != 0 && sum == S){
		answer++;
	}
	for (int i = index + 1; i <= N; i++){
		if (!selected[i]){
			selected[i] = true;
			solve(i, sum + v[i]);
			selected[i] = false;
		}
	}
}
int main(){
	cin >> N; cin >> S;
	v.push_back(0);
	answer = 0;
	for (int i = 0; i < N; i++){
		int insert;
		cin >> insert;
		v.push_back(insert);
	}
	solve(0, 0);
	printf("%d", answer);
}
