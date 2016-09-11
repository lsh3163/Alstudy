#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
int Order;
int main(void){
	cin >> s;
	int len = s.length();
	stack<char> left;
	stack<char> right;
	for (int i = 0; i < len; i++){
		left.push(s[i]);
	}
	cin >> Order;
	while (Order--){
		char input;
		cin >> input;
		if (input == 'P'){
			char push_element;
			cin >> push_element;
			left.push(push_element);
		}
		else if (input == 'L'){
			if (!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		else if (input == 'B'){
			if (!left.empty()){
				left.pop();
			}
		}
		else if (input == 'D'){
			if (!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}
	}
	while (!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()){
		printf("%c", right.top());
		right.pop();
	}
}
