#include <iostream>
#include <string>
using namespace std;

int alpha[26];
int solve(string str, int start){
	int tmp = start;
	for(int i=start+1;i<26;i++){
		if((str[i] < str[tmp]) && (str[i] > str[start-1])) tmp=i;
	}
	return tmp;
}
int main() {
	string s;
	cin >> s;
	
	int len = s.length();
	for(int i=0;i<len;i++){
		alpha[s[i]-'a']++;
	}
	if(len < 26){
		char x = 'a';
		for(int i=0;i<26;i++){
			if(alpha[i]==0){
				x += i;
				break;
			}
		}
		cout << s << x;
		//printf("%c",x);
	}
	else{
		for(int i=24;i>=0;i--){
			int min = solve(s, i+1);
			if(s[i] < s[min]){
				s[i] = s[min];
				for(int k=0;k<=i;k++){
					printf("%c",s[k]);
				}
				return 0;
			}
			
		}
		printf("-1");
	}
	
}
