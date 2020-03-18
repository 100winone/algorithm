/*3055 탈출 BFS 20200318*/
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#define MAX 51
using namespace std;
char a[MAX][MAX];
int d[MAX][MAX];
int water[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue <pair<int, int>> q;
void bfs(int n, int m){
    memset(water, -1, sizeof(water));
    int sx, sy, ex, ey;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] == '*'){
                q.push(make_pair(i, j));
                water[i][j] = 0;
            } else if(a[i][j] == 'S'){
                sx = i;
                sy = j;
            } else if(a[i][j] == 'D'){
                ex = i;
                ey = j;
            }
        }
    }
    while(!q.empty()){
//        int x = q.front().first;
//        int y = q.front().second;
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(water[nx][ny] != -1) continue;
            if(a[nx][ny] =='X') continue;
            if(a[nx][ny] =='D') continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    memset(d, -1, sizeof(d));
    q.push(make_pair(sx, sy));
    d[sx][sy] = 0;
    while(!q.empty()){
//        int x = q.front().first;
//        int y = q.front().second;
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(d[nx][ny] != -1) continue;
            if(a[nx][ny] == 'X') continue;
            if(water[nx][ny] != -1 && d[x][y] + 1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    if(d[ex][ey] == -1){
        cout << "KAKTUS\n";
    } else {
        cout << d[ex][ey] << "\n";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    bfs(n, m);
    return 0;
}