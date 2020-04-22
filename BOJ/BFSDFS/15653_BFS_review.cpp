/*15653 구슬 탈출4*/
#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX 11

using namespace std;
int N, M;
int rx, ry, bx, by, hx, hy;
int cnt;
int dx [] = {-1, 1, 0, 0};
int dy [] = {0, 0, -1, 1};
char graph[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
bool flag;
queue <pair<int,int>> redBall;
queue <pair<int,int>> blueBall;

void bfs(){
    while(!redBall.empty()){
        int qsize = redBall.size();
        while(qsize--){
            rx = redBall.front().first;
            ry = redBall.front().second;
            bx = blueBall.front().first;
            by = blueBall.front().second;
            redBall.pop();
            blueBall.pop();

            if(rx == hx && ry == hy){
                flag = true;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                int nbx = bx + dx[i];
                int nby = by + dy[i];

                while(1){
                    if(graph[nrx][nry] == '#'){
                        nrx -= dx[i];
                        nry -= dy[i];
                        break;
                    }
                    if(graph[nrx][nry] == 'O')
                        break;
                    nrx += dx[i];
                    nry += dy[i];
                }
                while(1){
                    if(graph[nbx][nby] == '#'){
                        nbx -= dx[i];
                        nby -= dy[i];
                        break;
                    }
                    if(graph[nbx][nby] == 'O')
                        break;
                    nbx += dx[i];
                    nby += dy[i];
                }
                if(nbx == hx && nby == hy) {
                    continue;
                }
                if(nrx == nbx && nry == nby){
                    switch (i){
                        case 0: rx > bx ? nrx++ : nbx++; break;
                        case 1: rx < bx ? nrx-- : nbx--; break;
                        case 2: ry > by ? nry++ : nby++; break;
                        case 3: ry < by ? nry-- : nby--; break;
                    }
                }
                if (visited[nrx][nry][nbx][nby])
                    continue;
                redBall.push(make_pair(nrx, nry));
                blueBall.push(make_pair(nbx, nby));
                visited[nrx][nry][nbx][nby] = true;
            }
        }
        if(flag) break;
        else cnt++;
    }
    if(flag)
        printf("%d\n", cnt);
    else printf("-1\n");
}

int main(){
    scanf("%d %d",&N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
            if(graph[i][j] == 'R'){
                redBall.push(make_pair(i, j));
                rx = i;
                ry = j;
            }
            if(graph[i][j] == 'B'){
                blueBall.push(make_pair(i, j));
                bx = i;
                by = j;
            }
            if(graph[i][j] == 'O') {
                hx = i;
                hy = j;
            }
        }
    }
    visited[rx][ry][bx][by] = true;
    bfs();

    return 0;
}