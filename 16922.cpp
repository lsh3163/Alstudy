#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1001];
int main() {
	
	int n;
	cin >> n;
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int k=0;k<=n-i-j;k++){
				for(int s=0;s<=n-i-j-k;s++){
					if((i + j + k + s)==n){
						arr[i + j * 5 + k * 10 + s * 50] ++;
						//printf("%d\n", i + j * 5 + k * 10 + s * 50);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=1000;i++){
		if(arr[i] > 0){
			ans++;
		}
	}
	printf("%d", ans);
    return 0;
}
