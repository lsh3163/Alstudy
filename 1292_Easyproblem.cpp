#include<stdio.h>
#include<iostream>
using namespace std;
int arr[1234];
void make_arr(){
	arr[0] = 0;
	int count = 1;
	int index = 1;
	while (index <= 1000)
	{
		for (int i = index; i < count + index; i++){
			arr[i] = count;
		}
		index = count + index;
		count++;
	}
}
int sum(int a, int b){
	int S = 0;
	for (int i = a; i <= b; i++)
	{
		S += arr[i];
	}
	return S;
}
int main(){
	int A, B;
	cin >> A;
	cin >> B;
	make_arr();
	int answer = sum(A, B);
	printf("%d", answer);
}
