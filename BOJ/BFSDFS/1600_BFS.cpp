/*1600 말이 되고픈 원숭이 BFS 20200330*/
#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
#define MAX 200
using namespace std;
int dx[] = {0, 0, 1, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};
int cost[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int map[MAX][MAX];
int d[MAX][MAX][31];
int w, h;
int k;
void BFS(){
    queue<tuple<int, int, int>> q;
    d[0][0][0] = 0;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()){
        int x, y, c;
        tie(x, y, c) = q.front();
        q.pop();
        for (int i = 0; i < 12; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c + cost[i];
            if ( nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(map[nx][ny] == 1) continue;
                if(nc <= k){
                    if(d[nx][ny][nc] == -1){
                        d[nx][ny][nc] = d[x][y][c] + 1;
                        q.push(make_tuple(nx, ny, nc));
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= k; ++i) {
        if(d[h - 1][w - 1][i] == -1) continue;
        if(ans == -1 || ans > d[h - 1][w - 1][i]){
            ans = d[h - 1][w - 1][i];
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> map[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    BFS();
    return 0;
}