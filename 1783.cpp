#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int main(){
	cin >> N; cin >> M;
	if (N == 1){
		printf("1");
	}
	if (N == 2){
		printf("%d", min(4, (M + 1) / 2));
	}
	if (N >= 3){
		if (M >= 7){
			printf("%d", M - 2);
		}
		else{
			printf("%d", min(4, M));
		}
	}
}
