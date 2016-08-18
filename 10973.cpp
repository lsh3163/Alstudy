#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int main(){
	cin >> N;
	vector<int> group;
	for (int i = 0; i < N; i++){
		int input;
		cin >> input;
		group.push_back(input);
	}
	if (prev_permutation(group.begin(), group.end())){
		for (int i = 0; i < N; i++){
			printf("%d ", group[i]);
		}
	}
	else{
		printf("-1");
	}
}
