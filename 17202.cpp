#include <iostream>
#include <vector>
#include <string>
using namespace std;
int board[100][100];
int main()
{
	string A, B;
	cin >> B >> A;
	
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0) board[0][i] = A[7-i/2] - '0';
		else board[0][i] = B[7-i / 2] - '0';
	}
	for (int i = 1; i < 16; i++) {
		for (int j = 14; j >= 0; j--) {
			board[i][j] = (board[i - 1][j] + board[i - 1][j + 1]) % 10;
		}
	}
	/*for (int i = 0; i < 16; i++) {
		
		for (int j = (15-i); j >=0 ; j--) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}*/
	printf("%d%d", board[14][1], board[14][0]);
}
