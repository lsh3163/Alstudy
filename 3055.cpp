#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

char ground[100][100];
int water[100][100];
int visited[100][100];
pair<int, int > start;
int n, m;

int mmove[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

// 좌표가 안에 있나요 없나요
bool isPossible(int h, int w) {
    if(h < 0 || w < 0 || h >= n || w >= m) return false;
    return true;
}


int main() {
    cin >> n >> m;
    // 좌표를 담아놓는 큐
    queue<pair<int, int > > que;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ground[i][j];
            visited[i][j] = 0;
            // 그냥 최대, 계속 min으로 갱신할 꺼기 때문에
            water[i][j] = 987654321;
            // 물이 있는 좌표는 1
            if(ground[i][j] == '*') {
                water[i][j] = 1;
                que.push(make_pair(i,j));
            }
            if(ground[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
        }
    }
    
    while(!que.empty()) {
        int hereH = que.front().first;
        int hereW = que.front().second;
        que.pop();
        for(int i = 0 ; i< 4; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            // 1 step 마다 water가 퍼지는 시간 저장
            if(isPossible(nextH, nextW) && water[nextH][nextW] > water[hereH][hereW] + 1 && ground[nextH][nextW] != 'D' && ground[nextH][nextW] != 'X') {
                que.push(make_pair(nextH, nextW));
                water[nextH][nextW] = water[hereH][hereW] + 1;
            }
        }
    }

    que.push(start);
    visited[start.first][start.second] = 1;
    while(!que.empty()) {
        int hereH = que.front().first;
        int hereW = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextH = hereH + mmove[i][0];
            int nextW = hereW + mmove[i][1];
            // water도달 시간과 고슴도치 도달 시간 비교 후, queue에 push
            if(isPossible(nextH, nextW) && water[nextH][nextW] - visited[hereH][hereW] > 1 && visited[nextH][nextW] == 0 && ground[nextH][nextW] != 'X') {
                que.push(make_pair(nextH, nextW));
                visited[nextH][nextW] = visited[hereH][hereW] + 1;
            }
            // 좌표가 D일 때 걸린 시간 출력 후 
            if(ground[nextH][nextW] == 'D') {
                cout << visited[hereH][hereW] << endl;
                return 0;
            }
        }
    }
    cout << "KAKTUS" << endl;
}
