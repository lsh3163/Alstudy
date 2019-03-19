#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for(int n=0;n<N;n++){
		cin >> v[n];
	}
	sort(v.begin(), v.end());
	for(int &x: v){
		printf("%d\n", x);
	}
}
