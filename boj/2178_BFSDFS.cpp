/*
 * 2178 미로탐색 문제 (메모리 부족)
 * */

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


int M, N;
bool check[101][101];
int graph[101][101];
int d[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init()
{
    //맵 초기화
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = 0;
            check[i][j] = false;
            d[i][j] = 0;
        }
    }
}

void bfs(int x, int y){
    d[0][0] = 1;
    check[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(graph[nextX][nextY] && !check[nextX][nextY]){
                    check[nextX][nextY] == true;
                    d[nextX][nextY] = d[x][y] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}
int main() {
    init();
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; ++j) {
            scanf("%1d", &graph[i][j]);
        }
    }

    bfs(0, 0);
    printf("%d\n", d[N - 1][M - 1]);
    return 0;
}
