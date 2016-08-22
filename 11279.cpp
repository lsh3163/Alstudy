#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int N;
int main(){
	priority_queue<int> mq;
	cin >> N;
	while (N--){
		int input;
		scanf("%d",&input);
		if (input > 0){
			mq.push(input);
		}
		else if (input == 0){
			if (!mq.empty()){
				printf("%d\n", mq.top());
				mq.pop();
			}
			else{
				printf("0\n");
			}
		}
	}
}
