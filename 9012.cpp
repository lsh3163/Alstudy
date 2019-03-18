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
		stack<char> st;
		int len = s.length();
		bool isright = false;
		for (int i = 0; i < len; i++){
			if (s[i] == '('){
				st.push('(');
			}
			else{
				if (!st.empty()){
					st.pop();
				}
				else {
					isright = true;
				}
			}
		}
		if (!st.empty()){
			isright = true;
		}
		if (isright) printf("NO\n");
		else{
			printf("YES\n");
		}
	}
}
