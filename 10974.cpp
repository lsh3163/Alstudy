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
		group.push_back(i + 1);
	}
	do{
		for (int i = 0; i < N; i++){
			printf("%d ", group[i]);
		}
		printf("\n");
	} while (next_permutation(group.begin(), group.end()));
}
