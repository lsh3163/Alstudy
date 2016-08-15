#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int memo[101][101];
string W, S;
bool isPattern(int w, int s){
	int &ret = memo[w][s];
	if (ret != -1){
		return ret;
	}
	if(w < W.size() && s < S.size() && (W[w] == S[s])){
		return ret = isPattern(w + 1, s + 1);
	}
	if (W.size() == w){
		return ret = (S.size() == s);
	}
	if (W[w] == '*'){
		if (isPattern(w + 1, s) || (s < S.size() && isPattern(w, s + 1))){
			return 1;
		}
	}
	return 0;
}
int main(){
	int N;
	cin >> W;
	cin >> N;
	while (N--){
		cin >> S;
		memset(memo, -1, sizeof(memo));
		if (isPattern(0, 0)){
			cout << S << endl;
		}
	}
}
