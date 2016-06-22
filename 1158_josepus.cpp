#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> answer;
void death(int p,int d){
	queue<int> q;
	int count = 0;
	for (int i = 1; i <= p; i++){
		q.push(i);
	}
	while (!q.empty()){
		int now = q.front();
		q.pop();
		if (count == d - 1){
			answer.push_back(now);
			count = 0;
		}
		else{
			q.push(now);
			count++;
		}
	}
}
int main(){
	int person, die;
	cin >> person;
	cin >> die;
	death(person, die);
	int len = answer.size();
	printf("<");
	for (int i = 0; i < len; i++){
		if (i != len - 1)
			printf("%d, ", answer[i]);
		else{
			printf("%d>", answer[i]);
		}
	}
}
