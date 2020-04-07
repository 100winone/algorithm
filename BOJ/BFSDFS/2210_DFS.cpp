/*2210 숫자판 점프 DFS 20200407*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
set <int> s;
void dfs(int x, int y, int cnt, int res){
    if(cnt == 5){
        s.insert(res);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            dfs(nx, ny, cnt + 1, res * 10 + a[nx][ny]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            dfs(i, j, 0, a[i][j]);
        }
    }
    cout << s.size() << '\n';
    return 0;
}