#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > v(N);
	for(int n=0;n<N;n++){
		int x, y;
		cin >> x >> y;
		v[n] = make_pair(x, y);
	}
	sort(v.begin(), v.end());
	for(pair<int, int> p : v){
		printf("%d %d\n", p.first, p.second);
	}
}
