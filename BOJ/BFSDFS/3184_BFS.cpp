/*3184 양 BFS 20200326*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int r, c;
char a[251][251];
int d[251*251][2];
bool check[251][251];
void bfs(int sx, int sy, int cnt){
     queue<pair<int, int>> q;
     q.push(make_pair(sx, sy));
     check[sx][sy] = true;
     while(!q.empty()){
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         if(a[x][y] =='v'){ // 늑대
             d[cnt][0] += 1;
         } else if(a[x][y] =='o'){ // 양
             d[cnt][1] += 1;
         }
         for (int i = 0; i < 4; ++i) {
             int nx = x + dx[i];
             int ny = y + dy[i];
             if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
             if(a[nx][ny] == '#') continue;
             if(check[nx][ny]) continue;
             q.push(make_pair(nx, ny));
             check[nx][ny] = true;
         }
     }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n;
    int cnt = 0;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if(a[i][j] != '#' && !check[i][j]){
                cnt += 1;
                bfs(i, j, cnt);
            }
        }
    }
    int v = 0;
    int o = 0;
    for (int i = 1; i <= cnt; ++i) {
        if(d[i][0] >= d[i][1]){
            v += d[i][0];
        } else{
            o += d[i][1];
        }
    }
    cout << o << ' ' << v << '\n';
    return 0;
}