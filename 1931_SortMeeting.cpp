#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int, int> > meeting;
int main(){
	cin >> N;
	meeting.resize(N);
	for (int i = 0; i < N; i++){
		cin >> meeting[i].second;
		cin >> meeting[i].first;
	}
	sort(meeting.begin(), meeting.end());
	int now = 0;
	int answer = 0;
	for (int i = 0; i < N; i++){
		if (now <= meeting[i].second){
			now = meeting[i].first;
			answer++;
		}
	}
	printf("%d", answer);
}
