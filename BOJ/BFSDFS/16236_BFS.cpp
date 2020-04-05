/*16236 아기상어 BFS + Simulation 느낌 20200405 Hard*/
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
tuple<int, int, int> bfs(vector<vector<int>> &a, int x, int y, int size){
    int n = a.size();
    vector<tuple<int, int, int>> ans;
    vector<vector<int>> d(n, vector<int> (n, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = 0;
    while(!q.empty()){
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1){
                bool ok = false;
                bool eat = false; // 아기 상어는 자신의 크기보다 큰 물고기 있는 곳 못지나감.
                if(a[nx][ny] == 0){ // 빈칸
                    ok = true;
                } else if(a[nx][ny] < size){ // 이동하고 먹기 둘 다 가능
                    ok = true;
                    eat = true;
                } else if(a[nx][ny] == size){
                    ok = true; // 지나가기만 가능
                }
                if(ok){ // 이동 가능
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                    if(eat){
                        ans.push_back(make_tuple(d[nx][ny], nx, ny));
                    }
                }
            }
        }
    }
    if(ans.empty()){
        return make_tuple(-1, -1, -1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n, 0));
    int x, y; // 상어 위치
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 9) {
                tie(x, y) = make_pair(i, j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while(true){
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(a, x, y, size);
        if(dist == -1) break;
        a[nx][ny] = 0;
        ans += dist;
        exp += 1;
        if(size == exp){
            size += 1;
            exp = 0;
        }
        tie(x, y) = make_pair(nx, ny);
    }
    cout << ans << '\n';
    return 0;
}