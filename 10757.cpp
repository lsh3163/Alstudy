#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool check;
vector<int> bigsum(string &a, string &b){
//나  있   자수 제  자수 1더
	vector<int> c(max(a.length(),b.length())+ 1);
	
	if (a.length() < b.length()){
		swap(a, b);
	}
	int bs = b.length();
	int as = a.length();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < bs; i++){
		int pushvalue = a[i] + b[i] - '0' - '0';
		c.push_back(pushvalue);
	}
	for (int i = bs; i < as; i++){
		int pushvalue = a[i] - '0';
		c.push_back(pushvalue);
	}
	int cs = c.size();
	for (int i = 0; i < cs-1; i++){
		if (c[i] >= 10){
//10 넘ㅡ 나머 남ㅜ 몫 ㅏ음다ㅜ 넘
			c[i + 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}
int main(){
	string a;
	string b;
	cin >> a >> b;
	vector<int> c = bigsum(a, b);
	reverse(c.begin(), c.end());
	if (check){
		for (int i = 0; i < max(a.length(), b.length()) + 1; i++){
			printf("%d", c[i]);
		}
		return 0;
	}
	for (int i = 0; i < max(a.length(),b.length()); i++){
		printf("%d", c[i]);
	}
return 0;
}
