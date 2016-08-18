#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> group;
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		int input;
		cin >> input;
		group.push_back(input);
	}
	int answer = 0;
	sort(group.begin(), group.end());
	do{
		int ret = 0;
		for (int i = 1; i < N; i++){
			ret += abs(group[i] - group[i - 1]);
		}
		answer = max(ret, answer);
	} while (next_permutation(group.begin(), group.end()));
	printf("%d\n", answer);
}
