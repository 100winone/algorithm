/*
 * 1012 유기농 배추문제
 * */

#include <cstdio>
#include <cstring>
using namespace std;


int T, M, N, K;
bool check[51][51];
int graph[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cnt;

void init()
{
    //맵 초기화
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = 0;
            check[i][j] = false;
        }
    }
}

void dfs(int x, int y){
    check[x][y] = true;
    for(int i = 0; i < 4; i++){ // 네 방향체크
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){ // 범위 내에 다음방향
            if(graph[nextX][nextY] == 1 && !check[nextX][nextY]) // 배추있고, 미방문상태
                dfs(nextX, nextY);
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int z = 0; z < T; z++){
        init();
        /*
         * 2차원배열 memset 썼을 때는 오답으로 나옴. 왜인지?*/
//        cnt = 0;
//        memset(graph, 0, sizeof(graph) / 4);
//        memset(check, false, sizeof(check) / 4);
        scanf("%d %d %d", &M, &N, &K);
        for(int i = 0; i < K; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[b][a] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if((graph[i][j]) == 1 && !check[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
