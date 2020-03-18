/*2206 벽부수고 이동하기 BFS 20200318*/
#include <stdio.h>
#include <tuple>
#include <queue>
#define MAX 1001
using namespace std;
int a[MAX][MAX];
int d[MAX][MAX][2];
int dx[] = {0, 0, -1 , 1};
int dy[] = {1, -1, 0, 0};
queue <tuple<int, int, int>> q;
void bfs(int n, int m){
    while(!q.empty()){
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == 0 && d[nx][ny][z] == 0){
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
            if(z == 0 && a[nx][ny] == 1 && d[nx][ny][z + 1] == 0){
                d[nx][ny][z + 1] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z + 1));
            }
        }
    }
    if(d[n][m][0] != 0 && d[n][m][1] != 0) {
        printf("%d\n", min(d[n][m][0], d[n][m][1]));
    } else if (d[n][m][0] != 0){
        printf("%d\n", d[n][m][0]);
    } else if (d[n][m][1] != 0){
        printf("%d\n", d[n][m][1]);
    } else {
        printf("-1\n");
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }
    d[1][1][0] = 1;
    q.push(make_tuple(1, 1, 0));
    bfs(n, m);
    return 0;
}