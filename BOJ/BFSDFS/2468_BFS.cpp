/*2468 안전 영역 BFS 20200406 */
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;
int n;
int a[MAX][MAX];
bool checked[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int highestRegion = 0;
int safeArea = 0;
int maxSafe = -1;
void BFS(int x, int y, int rainCnt){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    checked[x][y] = true;
    while(!q.empty()){
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(a[nx][ny] > rainCnt){
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !checked[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    checked[nx][ny] = true;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if(a[i][j] > highestRegion) highestRegion = a[i][j];
        }
    }

    for (int i = 0; i <= highestRegion; ++i) {
        memset(checked, false, sizeof(checked));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if(!checked[j][k] && a[j][k] > i){
                    BFS(j, k, i);
                    safeArea += 1;
                }
            }
        }
        maxSafe = max(safeArea, maxSafe);
        safeArea = 0;
    }
    cout << maxSafe << '\n';
    return 0;
}