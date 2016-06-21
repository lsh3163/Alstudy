#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		string s;
		cin >> s;
		stack<int> st1, st2;
		for (int i = 0; i < s.length(); i++){
			//<이거나 >일 때 옮길 스택이 비어있는지 확인하고
			//비어있지 않다면 top을 다른 편 스택에 push하고 원래 스택을 pop
			if (s[i] == '<'){
				if (!st1.empty()){
					st2.push(st1.top());
					st1.pop();
				}
			}
			else if (s[i] == '>'){
				if (!st2.empty()){
					st1.push(st2.top());
					st2.pop();
				}
			}
			else if (s[i] == '-'){
				if(!st1.empty()) 
					st1.pop();
			}
			else{
				st1.push(s[i]);
			}
		}
		while (!st1.empty()){
			st2.push(st1.top());
			st1.pop();
		}
		while (!st2.empty()){
			printf("%c", st2.top());
			st2.pop();
		}
		printf("\n");

	}
}
