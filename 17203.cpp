#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a[1002];
int N, Q;
int main()
{
	
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	while (Q--) {
		int u, v;
		cin >> u >> v;
		if (u == v || v - 1 < u) {
			printf("0\n");
			continue;
		}
		int ans = 0;
		int cnt = v - u; 
		int k = 0;
		for (int i = 0; i < cnt; i++) {
			ans += abs(a[u+k] - a[u+k+1]);
			k++;
		}
		printf("%d\n", ans);
	}
}
