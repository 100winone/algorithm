/*1261 알고스팟 BFS 20200318*/
#include <stdio.h>
#include <queue>
#define MAX 101
using namespace std;
bool checked[MAX][MAX];
int d[MAX][MAX];
int a[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> nextQ;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int n, int m){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                if(!checked[nx][ny] && a[nx][ny] == 0){
                    d[nx][ny] = d[x][y];
                    q.push(make_pair(nx, ny));
                    checked[nx][ny] = true;
                }
                if(!checked[nx][ny] && a[nx][ny] == 1){
                    d[nx][ny] = d[x][y] + 1;
                    nextQ.push(make_pair(nx, ny));
                    checked[nx][ny] = true;
                }
            }
        }
        if(q.empty()){
            q = nextQ;
            nextQ = queue<pair<int, int>> ();
        }
    }
}
int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }
    q.push(make_pair(1, 1));
    checked[1][1] = true;
    d[1][1] = 0;
    bfs(n, m);
    printf("%d\n", d[n][m]);
    return 0;
}

