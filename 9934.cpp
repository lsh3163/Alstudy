#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > tree;
vector<int> data;
int n, m;

vector<int> slice(vector<int> data, int b, int e){
	vector<int> slice;
	for (int i = b; i < e; i++){
		slice.push_back(data[i]);
	}
	return slice;
}

void traversal(vector<int> data, int height){
	if (data.size() == 1){
		tree[height].push_back(data[0]);
		return;
	}
	int rootidx = data.size() / 2;
	int length = data.size();
	traversal(slice(data, 0, rootidx), height + 1);
	traversal(slice(data, rootidx + 1, length), height + 1);
	tree[height].push_back(data[rootidx]);
}

int main(void){
	cin >> n;
	tree.resize(n);
	m = 1;
	for (int i = 1; i <= n; i++){
		m *= 2;
	}
	m--;
	for (int i = 0; i < m; i++){
		int input;
		cin >> input;
		data.push_back(input);
	}
	traversal(data, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < tree[i].size(); j++){
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}
}
