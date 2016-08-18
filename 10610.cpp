#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	//3의 배수 인지 판별
	int len = s.size();
	int sum = 0;
	bool check = false;
	for (int i = 0; i < len; i++){
		sum += (s[i] - '0');
		if ((s[i] - '0') == 0){
			check = true;
		}
	}
	//오름차순 정렬
	if (sum % 3 == 0 && check){
		sort(s.begin(), s.end());
		for (int i = len - 1; i >= 0; i--){
			printf("%c", s[i]);
		}
	}
	//-1출력
	else{
		printf("-1");
	}
}
