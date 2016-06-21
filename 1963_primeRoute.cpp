#include<stdio.h>
#include<iostream>
#include<queue>
#define MAX 10000
using namespace std;
bool prime[MAX + 1];
bool visited[MAX + 1];
//소수인지 아닌지를 참 거짓으로 1~`10000까지 배열 prime에 저장
void erathos(){
	for (int i = 0; i < MAX + 1; i++){
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i*i < MAX + 1; i++){
		for (int j = i + i; j < MAX + 1; j += i){
			prime[j] = false;
		}
	}
}
int bfs(int n1,int n2){
	for (int i = 0; i < MAX + 1; i++){
		visited[i] = false;
	}
	queue<pair<int,int > > q;
	visited[n1] = true;
	q.push(make_pair(n1,0));
	//n1을 push하고 횟수는 0이라 저장
	while (!q.empty()){
		//해당 정점에서의 소수와 횟수를 불러옴
		int number = q.front().first;
		int count = q.front().second;
		q.pop();
		if (number == n2){
			return count;
		}
		//n1의 1000의 자리숫자를 1~9 중 하나로 체인지
		for (int i = 1; i <= 9; i++){
			int next = number % 1000 + i * 1000;
			//갈 숫자가 방문한 적없고 이것이 소수라면 push
			if (!visited[next] && prime[next]){
				visited[next] = true;
				q.push(make_pair(next, count + 1));
			}
		}
		//100의 자리수1~9로 Change
		for (int i = 0; i <= 9; i++){
			int next = number % 100 + i * 100 + (number / 1000)*1000;
			if (!visited[next] && prime[next]){
				visited[next] = true;
				q.push(make_pair(next, count + 1));
			}
		}
		//10의 자리수1~9로 Change
		for (int i = 0; i <= 9; i++){
			int next = number % 10 + i * 10 + (number / 100) * 100;
			if (!visited[next] && prime[next]){
				visited[next] = true;
				q.push(make_pair(next, count + 1));
			}
		}
		//1의 자리수1~9로 Change
		for (int i = 1; i <= 9; i++){
			int next = (number / 10) * 10 + i;
			if (!visited[next] && prime[next]){
				visited[next] = true;
				q.push(make_pair(next, count + 1));
			}
		}
	}
	return -1;
}
int main(){
	int T;
	cin >> T;
	erathos();
	while (T--){
		int num1, num2;
		cin >> num1;
		cin >> num2;
		int answer = bfs(num1, num2);
		if (answer == -1) printf("Impossible\n");
		else printf("%d\n", answer);
	}
}
