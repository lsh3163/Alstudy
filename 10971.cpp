#include<stdio.h>
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int w[20][20];
vector<int> group;
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		group.push_back(i + 1);
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> w[i][j];
		}
	}
	int answer = INT_MAX;
	do{
		bool check = true;
		int ret = 0;
		for (int i = 0; i < N - 1; i++){
			int start = group[i];
			int tar = group[i + 1];
			if (w[start][tar] == 0){
				check = false;
			}
			else{
				ret += w[start][tar];
			}
		}
		if (check && w[group[N - 1]][group[0]] != 0){
			ret += w[group[N - 1]][group[0]];
			if (answer > ret){
				answer = ret;
			}
		}
	} while (next_permutation(group.begin(), group.end()));
	printf("%d", answer);
}
