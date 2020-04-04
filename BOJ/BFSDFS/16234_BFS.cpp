/*16234 인구이동 BFS 20200404*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool bfs(vector<vector<int>> &a, int L, int R){
    int n = a.size();
    vector<vector<bool>> c(n, vector<bool>(n));
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(c[i][j] == false){
                queue<pair<int, int>> q;
                q.push(make_pair(i, j)); // 시작점
                c[i][j] = true;
                stack<pair<int, int>> s;
                s.push(make_pair(i, j)); // 방문기록 왜냐면 q는 없어질것이기 때문
                int sum = a[i][j];
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n){
                            if(c[nx][ny]) continue;
                            int diff = a[nx][ny] - a[x][y];
                            if(diff < 0) diff = -diff;
                            if(L <= diff && R >= diff){
                                q.push(make_pair(nx, ny));
                                s.push(make_pair(nx, ny));
                                c[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / s.size();
                while(!s.empty()){
                    int x, y;
                    x = s.top().first;
                    y = s.top().second;
                    s.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    while(true){
        if(bfs(a, L, R)){
            ans += 1;
        } else {
            break;
        }
    }
    cout << ans <<'\n';
    return 0;
}