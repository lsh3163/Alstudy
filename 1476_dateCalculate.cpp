#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int E; int S; int M;
	//1<=E<=15
	//1<=S<=28
	//1<=M<=19
	int answer = 0;
	cin >> E; cin >> S; cin >> M;
	int e = 0;
	int s = 0;
	int m = 0;
	while (true){
		if (e == E && s == S && m == M){	
			break;
		}
		e++; s++; m++;
		if (e >= 16){
			e = 1;
		}
		if (s >= 29){
			s = 1;
		}
		if (m >= 20){
			m = 1;
		}
		answer++;
	}
	printf("%d", answer);
}
