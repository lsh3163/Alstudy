#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > myqueue;
int N;
int main(){
	cin >> N;
	while (N--){
		int input;
		scanf("%d",&input);
		if (input > 0){
			myqueue.push(input);
		}
		else if (input == 0){
			if (!myqueue.empty()){
				printf("%d\n", myqueue.top());
				myqueue.pop();
			}
			else{
				printf("0\n");
			}
		}
	}
}
