#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
//STL을 활용해서 queue 구현_10845
int main(){
	//받을 명령의 개수 선언 및 입력
	int N;
	cin >> N;
	//q라는 이름을 가진 int형 queue 선언
	queue<int> q;
	//명령 하나 받을 때마다 N을 1씩 줄임
	while (N--){
		//받을 명령어(문자열)을 입력받음
		string s;
		cin >> s;
		//받은 문자열이 push 면 정수를 입력받고 이를 큐에다가 push
		if (s == "push"){
			int insert;
			cin >> insert;
			q.push(insert);
		}
		else if (s == "pop"){
			//q가 비었으면 -1을 출력
			if (q.empty()){
				printf("-1\n");
			}
			//q가 비지 않았으면 가장 앞에 있는 정수를 빼고 그 수를 출력
			else{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		//s가 size이면 큐에 있는 정수의 개수를 출력
		else if (s == "size"){
			printf("%d\n", q.size());
		}
		//s가 empty일 때 큐가 비면 1,아니면 0
		else if (s == "empty"){
			if (q.empty()){
				printf("1\n");
			}
			else printf("0\n");
		}
		//s가 front 일 때 큐에 정수가 없으면 -1 출력 아니면 가장 앞에 있는 정수 출력
		else if (s == "front"){
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if (s == "back"){
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
}
