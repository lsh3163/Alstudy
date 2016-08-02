#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> Num;
int main(void){
	cin >> N;
	Num.resize(N);
	for (int i = 0; i < N; i++){
		cin >> Num[i];
	}
	sort(Num.begin(), Num.end());
	cin >> M;
	vector<int> print;
	while (M--){
		int input;
		cin >> input;
		print.push_back(upper_bound(Num.begin(), Num.end(), input) - lower_bound(Num.begin(), Num.end(), input));
	}
	int len = print.size();
	for (int i = 0; i < len; i++){
		printf("%d ", print[i]);
	}
}
