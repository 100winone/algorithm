/*14502 연구소 BFS + recursive 20200329*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 9
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int map[MAX][MAX];
int temp[MAX][MAX];
int n, m;
int res;
void BFS(){
    int spreadMap[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            spreadMap[i][j] = temp[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(spreadMap[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(spreadMap[nx][ny] == 0) {
                    spreadMap[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(spreadMap[i][j] == 0) cnt++;
        }
    }
    res = max(res, cnt);
}
void makeWall(int wallCnt){
    if(wallCnt == 3){
        BFS();
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                makeWall(wallCnt + 1);
                temp[i][j] = 0;
            }
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 0){
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < m; ++l) {
                        temp[k][l] = map[k][l];
                    }
                }
                temp[i][j] = 1;
                makeWall(1);
                temp[i][j] = 0;
            }
        }
    }
    cout << res << '\n';
}