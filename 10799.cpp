#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int len = s.length();
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < len; i++){
		if (s[i] == '('){
			st.push(i);
		}
		else if (s[i] == ')'){
			int top = st.top();
			if ((i - top) == 1){
				st.pop();
				ans += st.size();
			}
			else{
				st.pop();
				ans++;
			}
		}
	}
	printf("%d", ans);
}
