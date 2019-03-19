#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b){
	if(b > a) return a;
	return b;
}
int max(int a, int b){
	if(b > a) return b;
	return a;
}
int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int k = min(x, y);
	int ans1 = a * x + b * y;
	int ans2 = c * k * 2 + a * (x - k) + b * (y - k);
	int ans3 = max(x, y) * c * 2;
	printf("%d", min(min(ans1, ans2), ans3));
    return 0;
}
