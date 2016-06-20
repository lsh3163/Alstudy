#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	//받을 명령어의 개수
	int N;
	cin >> N;
	//연산을 할 stack st선언
	stack<int> st;
	while (N--){
		//어떤 명령어 인지 판별할 string 변수 strg선언
		string s;
		cin >> s;
		if (s == "push"){
			//스택에 push 할 정수를 입력받음
			int insert;
			cin >> insert;
			//push연산
			st.push(insert);
		}
		else if (s == "pop"){
			int output = -1;
			//스택에 들어있는 정수가 없으면 -1출력
			//아니면 가장 위에 있는 정수를 빼고, 그 수를 출력
			if (!st.empty()){
				output = st.top();
				st.pop();
			}
			printf("%d\n", output);
		}
		else if (s == "size"){
			//size연산을 통하여 스택의 크기를 출력
			printf("%d\n", st.size());
		}
		else if (s == "top"){
			int output = -1;
			//비어 있지 않다면 스택의 탑을 출력시킴
			if (!st.empty()){
				output = st.top();
			}
			printf("%d\n", output);
		}
		else if (s == "empty"){
			//0로 초기화 후 스택이 비어있으면 1을 출력시킴 
			int output = 0;
			if (st.empty()){
				output = 1;
			}
			printf("%d\n", output);
		}
	}
}
