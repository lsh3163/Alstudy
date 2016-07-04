#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int d1[123];
struct wire{
	int left;
	int right;
};
wire wires[123];
bool cmp_wire(const wire &a,const wire &b){
	return a.left < b.left;
}
int lis(int idx){
	if (idx == N){
		return 0;
	}
	int &ret = d1[idx];
	if (ret != -1){
		return ret;
	}
	ret = 1;
	for (int i = idx + 1; i < N; i++){
		if (wires[idx].right < wires[i].right){
			ret = max(ret, lis(i) + 1);
		}
	}
	return ret;
}

int main(){
	cin >> N;
	for (int i = 0; i < 123; i++){
		d1[i] = -1;
	}
	for (int i = 0; i < N; i++){
		cin >> wires[i].left;
		cin >> wires[i].right;
	}
	sort(wires, wires + N, cmp_wire);
	int answer = 0;
	for (int i = 0; i < N; i++){
		answer = max(answer, lis(i));
	}
	printf("%d", N - answer);
}
