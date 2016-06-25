#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v;
vector<int> answer;
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		int insert;
		cin >> insert;
		v.push_back(insert);
	}
	sort(v.begin(), v.end());
	int M;
	cin >> M;
	int input;
	for (int i = 0; i < M; i++){
		cin >> input;
		int low = 0;
		int high = N - 1;
		int mid;
		while (low <= high){
			mid = (low + high) / 2;
			if (v[mid] > input){
				high = mid - 1;
			}
			else if (v[mid] < input){
				low = mid + 1;
			}
			else{
				answer.push_back(1);
				break;
			}
		}
		if (v[mid] != input){
			answer.push_back(0);
		}
	}
	for (int i = 0; i < M; i++){
		printf("%d\n", answer[i]);
	}
}
