#include <iostream>
#include <queue>
using namespace std;

int N, M, P, si[10], ans[10], board[1001][1001];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<int> q;
queue<pair<int,int>> q2[10];

bool isIn(int x, int y){
	return x>=1 && y>=1 && x<=N && y<=M;
}

int main() {
	cin >> N >> M >> P;
	for(int i=1;i<=P;i++){
		cin >> si[i];
		q.push(i);
	}
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			char x;
			cin >> x;
			if(x=='.') board[n][m] = 0;
			else if(x=='#'){
				board[n][m] = -1;
			}
			else{
				board[n][m] = x - '0';
				q2[board[n][m]].push(make_pair(n, m));
				ans[board[n][m]]++;
			}
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<si[now];i++){
			int qs = q2[now].size();
			
			if(qs==0) break;
			while(qs--){
				int nowx = q2[now].front().first;
				int nowy = q2[now].front().second;
				q2[now].pop();
				
				for(int d=0;d<4;d++){
					int nextx = nowx + dx[d];
					int nexty = nowy + dy[d];
					
					if(!isIn(nextx, nexty) || board[nextx][nexty]!=0) continue;
					board[nextx][nexty] = now;
					ans[now]++;
					q2[now].push(make_pair(nextx, nexty));
					
				}
				
			}
		}
		if(q2[now].size()) q.push(now);
	}
	for(int i=1;i<=P;i++){
		printf("%d ", ans[i]);
	}
}
