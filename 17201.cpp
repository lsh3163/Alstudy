#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	for (int i = 1; i < N * 2; i++) {
		if (abs(s[i] - s[i - 1])!=1) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
