#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int L, C;
vector<char> v;
char sel[20];
void solve(int idx, int cnt){
	if (cnt == L){
		int check = 0;
		for (int i = 0; i < L; i++){
			if (sel[i] == 'a' || sel[i] == 'e' || sel[i] == 'i' || sel[i] == 'o' || sel[i] == 'u'){
				check++;
			}
		}
		if (check == 0){
			return;
		}
		else if (check >= L - 1){
			return;
		}
		else if (check > 0 && check <= L - 2){
			for (int i = 0; i < L; i++){
				printf("%c", sel[i]);
			}
			printf("\n");
		}
		return;
	}
	if (idx == C){
		return;
	}
	sel[cnt] = v[idx];
	solve(idx + 1, cnt + 1);
	solve(idx + 1, cnt);
}
int main(){
	cin >> L; cin >> C;
	for (int i = 0; i < C; i++){
		char input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	solve(0, 0);
}
