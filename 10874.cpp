#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int answersheet[11];
int N;
vector<int> answer;
int main(){
	cin >> N;
	for (int i = 1; i <= 10; i++){
		answersheet[i] = (i - 1) % 5 + 1;
	}
	for (int i = 1; i <= N; i++){
		bool retest = true;
		for (int j = 1; j <= 10; j++){
			int input;
			cin >> input;
			if (answersheet[j] != input){
				retest = false;
			
			}
		}
		if (retest){
			answer.push_back(i);
		}
	}
	int len = answer.size();
	for (int i = 0; i < len; i++){
		printf("%d\n", answer[i]);
	}
}
