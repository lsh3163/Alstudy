#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
//1~3x=>y
void solve(int n,int x, int y){
	if (n == 0){
		return;
	}
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}
int main(){
	//20이 N제한이기 때문에 가능
	cin >> N;
	int answer = (1 << N) - 1;
	printf("%d\n", answer);
	solve(N, 1, 3);
}
