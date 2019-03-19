#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char now[321][321];
char arr[321][321];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main() {
	// your code goes here
	int R, C, N;
	cin >> R >> C >> N;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin >> now[i][j];
		}
	}
	if(N % 2 == 0){
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				printf("O");
			}
			printf("\n");
		}
		return 0;
	}
	else{
		
		while(N>1){
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					arr[i][j]='.';
				}
			}
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					if(now[i][j]=='O'){
						arr[i][j]='O';
						for(int d=0;d<4;d++){
							int nx = i + dx[d];
							int ny = j + dy[d];
							if(nx>=1 && nx<=R && ny<=C && ny>=1){
								arr[nx][ny] = 'O';
							}
						}
					}
				}
			}
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					if(arr[i][j]=='.'){
						now[i][j] = 'O';
					}
					else{
						now[i][j] = '.';
					}
				}
			}
			N-=2;
			
		}
		for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					printf("%c", now[i][j]);
				}
			printf("\n");
		}
		
	}
	return 0;
}
