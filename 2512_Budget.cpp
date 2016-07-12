#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	
	long long int N;
	cin >> N;

	vector<long long int> v;
	v.resize(N);
	long long int end = 0;
	for (int i = 0; i < N; i++){
		cin >> v[i];
		end = max(end, v[i]);
	}

	long long int maxi;
	cin >> maxi;
	long long int start = maxi / N;
	long long int sum = 0;
	long long int mid;
	long long int ans = 0;
	while (start <= end){
		mid = (end + start) / 2;
		sum = 0;
		for (int i = 0; i < N; i++){
			if (mid < v[i]){
				sum += mid;
			}
			else{
				sum += v[i];
			}
		}
		if (sum > maxi){
			end = mid - 1;
		}

		if (sum <= maxi){
			ans = max(ans, mid);
			start = mid + 1;
		}
	}
	printf("%lld", ans);
}
