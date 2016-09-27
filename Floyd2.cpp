#include <cstdio>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include<vector>
using namespace std;
int n;
int d[101][101];
int m;
int nex[101][101];
vector<int> path(int u, int v){
	vector<int> ret;
	if (nex[u][v]==0){
		return ret;
	}
	ret.push_back(u);
	while (u != v){
		u = nex[u][v];
		ret.push_back(u);
	}
	return ret;
}
int main(){
	cin >> n >> m;
	while (m--){
		int u, v, x;
		cin >> u >> v >> x;
		if (d[u][v] == 0){
			d[u][v] = x;
		}
		else{
			d[u][v] = min(d[u][v], x);
		}
		nex[u][v] = v;
	}
	for (int k = 1; k <= n; k ++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0){
					if (d[i][j] == 0){
						d[i][j] = d[i][k] + d[k][j];
						nex[i][j] = nex[i][k];
					}
					else{
						if (d[i][j] > d[i][k] + d[k][j]){
							nex[i][j] = nex[i][k];
						}
						d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			vector<int> p = path(i, j);
			if (p.size() == 0 || (i==j)){
				printf("0");
				printf("\n");
				continue;
			}
			else{
				int size = p.size();
				printf("%d ", p.size());
				for (int k = 0; k < size; k++){
					printf("%d ", p[k]);
				}
			}
			printf("\n");
		}
	}
	_getch();
	return 0;
}
