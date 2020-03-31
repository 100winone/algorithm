/*10026 적록색약 BFS 20200331*/
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#define MAX 100
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
string map[MAX];
bool check[MAX][MAX];
int n;

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    char ch = map[x][y];
    while(!q.empty()){
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(check[nx][ny]) continue;
            if(map[nx][ny] != ch) continue;
            q.push(make_pair(nx, ny));
            check[nx][ny] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!check[i][j]) {
                BFS(i, j);
                cnt += 1;
            }
        }
    }
    cout << cnt << ' ';

    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!check[i][j]) {
                BFS(i, j);
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}