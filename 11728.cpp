#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> num;
int main(){
	cin >> N; cin >> M;
	for (int i = 0; i < (N + M); i++){
		int input;
		scanf("%d",&input);
		num.push_back(input);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < (N + M); i++){
		printf("%d ", num[i]);
	}

}
