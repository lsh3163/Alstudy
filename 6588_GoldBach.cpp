#include <stdio.h>
#include <iostream>
#include <string.h>
#define SIZE 1000000
using namespace std;
bool is_prime[SIZE];
int N;
void erathos(){
	memset(is_prime, true, SIZE);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i*i < SIZE; i++){
		for (int j = i + i; j < SIZE; j += i){
			is_prime[j] = false;
		}
	}
}
int main() {
	erathos();
	while (true){
		scanf("%d",&N);
		if (N == 0){
			break;
		}
		int a = 0;
		int b = 0;
		for (int i = 1; i <= N; i++){
			if (is_prime[i] && is_prime[N - i]){
				if (i % 2 == 1 && (N - i) % 2 == 1){
					a = i;
					b = N - i;
					break;
				}
			}
		}
		if (a == 0 && b == 0){
			printf("Goldbach's conjecture is wrong.\n");
		}
		if (a != 0 && b != 0){
			printf("%d = %d + %d\n", N, a, b);
		}
	}
}
