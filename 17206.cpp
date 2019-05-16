#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int T;
bool a[80001];
int d[80001];
int main()
{
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		int n;
		scanf("%d", &n);
		int three = n / 3;
		int seven = n / 7;
		int iou = n / 21;
		printf("%d\n", 3 * (three)*(three+1)/2 + 7*(seven)*(seven+1)/2 - 21*(iou)*(iou+1)/2);
	}
	

}
