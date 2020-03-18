/*보물섬 2589번*/
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iostream>
#define MAX 51

using namespace std;
char graph[MAX][MAX];
bool check[MAX][MAX];
int dist[MAX][MAX];


int N, M;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int maxValue;

void bfs(int x, int y){
    memset(dist, 0, sizeof(dist));
    queue <pair<int, int>> q;
    q.push(make_pair(x, y));
    dist[x][y] = 1;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            maxValue = max(maxValue, dist[curX][curY]);
            if(nextX >= 0 && nextX < N && nextY >=0 && nextY < M){
                if(graph[nextX][nextY] == 'L' && dist[nextX][nextY] == 0){
                    q.push(make_pair(nextX, nextY));
                    dist[nextX][nextY] = dist[curX][curY] + 1;
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; j++) {
            if(graph[i][j] == 'L'){
                bfs(i, j);
            }
        }
    }
    printf("%d\n", maxValue - 1);
}