#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n, m, k;
int main(){
	cin >> n; cin >> m; cin >> k;
	int output=0;
	while (n >= 2 && m >= 1 && (n + m) >= (k + 3)){
		n -= 2;
		m--;
		output++;
	}
	printf("%d", output);
}
