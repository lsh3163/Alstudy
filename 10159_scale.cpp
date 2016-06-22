#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int graph1[123][123];
bool visited1[123];
bool visited2[123];
int graph2[123][123];
void dfs1(int n){
	visited1[n] = true;
	for (int i = 1; i <= 100; i++){
		if (!visited1[i] && graph1[n][i] == 1){
			dfs1(i);
		}
	}

}
void dfs2(int n){
	visited2[n] = true;
	for (int i = 1; i <= 100; i++){
		if (!visited2[i] && graph2[n][i] == 1){
			dfs2(i);
		}
	}
}
int main(){
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u;
		cin >> v;
		graph1[u][v] = 1;
		graph2[v][u] = 1;
	}
	for (int i = 1; i <= N; i++){
		memset(visited1, false, 123);
		memset(visited2, false, 123);
		dfs1(i);
		dfs2(i);
		int count = 0;
		for (int j = 1; j <= N; j++){
			if (visited1[j] || visited2[j]){
				count++;
			}
		
		}
		printf("%d\n", N - count);
	
	}
}
