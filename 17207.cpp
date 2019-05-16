#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int a[5][5];
int b[5][5];
int result[5][5];
int main()
{
	vector<string> v;
	v.push_back("Inseo");
	v.push_back("Junsuk");
	v.push_back("Jungwoo");
	v.push_back("Jinwoo");
	v.push_back("Youngki");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	int ret = 0x7fffffff;
	int idx = 0;
	for (int i = 4; i >= 0; i--) {
		int ans = 0;
		for (int j = 0; j < 5; j++) {
			ans += result[i][j];
		}
		if (ans < ret) {
			ret = ans;
			idx = i;
		}
		//printf("%d ", ans);
	}
	cout << v[idx];
}
