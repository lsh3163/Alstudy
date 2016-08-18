#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int inorder[100000];
int postorder[100000];
int position[100001];
//postorder로부터 루트를 찾고
//inorder에서 그 값을 찾아 왼쪽과 오른쪽으로 나눈다.
void solve(int in_start, int in_end, int post_start, int post_end){
	//종료조건
	if (in_start > in_end || post_start > post_end){
		return;
	}
	//postorder 맨 끝이 루트이므로
	int root = postorder[post_end];
	//preorder이기 때문이죠 "루트 먼저"
	printf("%d ", root);
	//inorder배열의 root index를 p에저장
	//inorder를 왼쪽과 오른쪽으로 나누기 위해서 입니다.
	int p = position[root];
	int left = p - in_start;
	//inorder에서 왼쪽 (p는 제외)
	solve(in_start, p - 1, post_start, post_start + left - 1);
	//inorder에서 오른쪽
	solve(p + 1, in_end, post_start + left, post_end - 1);
}
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> inorder[i];
	}
	for (int i = 0; i < N; i++){
		cin >> postorder[i];
	}
	for (int i = 0; i < N; i++){
		position[inorder[i]] = i;
	}
	solve(0, N - 1, 0, N - 1);
}
