/*2178 미로탐색 BFS 20200318*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool checked[101][101];
char a[101][101];
int dis[101][101];
queue<pair<int, int>> q;
void bfs(int n, int m){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                if(a[nx][ny] == '1' && !checked[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    dis[nx][ny] = dis[x][y] + 1;
                    checked[nx][ny] = true;
                }
            }
        }
    }
    cout << dis[n][m] << '\n';
//    printf("%d\n", dis[n][m]);
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    q.push(make_pair(1, 1));
    checked[1][1] = true;
    dis[1][1] = 1;
    bfs(n, m);
}