#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
//W[i][j]의 정의 i도시에서 j도시로 가는 비용
int W[16][16];
//도시의 수
int n;
//Memoization 배열
int memo[16][1 << 16];
//here은 현재 정점이고
//visited = 10001(2)이런식으로 저장되어 있습니다.
int solveTSP(int here, int visited){
	//다 방문했다는 뜻이므로 0번도시로 돌아가고 종료합니다.
	if (visited == ((1 << n) - 1)){
		return W[here][0];
	}
	//현재 도시와 방문정보를 불러옵니다.
	int &ret = memo[here][visited];
	if (ret != -1){
		return ret;
	}
	//최소값을 찾아야 하기 때문에 이렇게 초기화 합니다.
	ret = 1000000 * 16 * 16;
	for (int next = 0; next < n; next++){
		if (visited & (1 << next)) continue;
		if (W[here][next] == 0) continue;
		ret = min(ret, W[here][next] + solveTSP(next, visited + (1 << next)));
	}
	return ret;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> W[i][j];
		}
	}
    memset(memo,-1,sizeof(memo));
	printf("%d", solveTSP(0, 1));
	return 0;
}
