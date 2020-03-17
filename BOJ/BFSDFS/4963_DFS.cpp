/*4963 섬의 개수 DFS 20200317*/
#include <stdio.h>
using namespace std;
int n, m;
int a[51][51];
bool checked[51][51];
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};
// 남, 북, 서, 동, 북동, 남동, 북서, 남서
void dfs(int x, int y){
    checked[x][y] = true;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(a[nx][ny] == 1 && !checked[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}
int main(){
    while(true){
        scanf("%d %d", &m, &n);
        if(n == 0 && m == 0)
            break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = 0;
                checked[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == 1 && !checked[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }


    return 0;
}