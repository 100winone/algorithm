/*2583 영역구하기 BFS 20200407*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX 100
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check[MAX][MAX];
vector<int> dist;

int m, n;
void bfs (int sx, int sy){
    bool move = false;
    int d = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!check[nx][ny]){
                    move = true;
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    d += 1;
                }
            }
        }
    }
    if(!move) d += 1;
    dist.push_back(d);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        int q, w, e ,r;
        cin >> q >> w >> e >> r;
        for (int j = q; j < e; ++j) { // q = 1 e = 3
            for (int k = w; k < r; ++k) { // w = 0 r = 2
            if(check[j][k]) continue;
            check[j][k] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(!check[i][j]){
                bfs(i, j);
            }
        }
    }
    int dSize = dist.size();
    cout << dSize << '\n';
    sort(dist.begin(), dist.end());
    for (int i = 0; i < dSize; ++i) {
        cout << dist[i] << ' ';
    }
    return 0;
}