/*17070 파이프 옮기기 1 BruteForce + DFS + 백트래킹 20200423*/
#include <iostream>
#include <cstring>
#define MAX 17
using namespace std;

int dx[] = { 0, 1, 1 }; // 가로, 세로, 대각
int dy[] = { 1, 0, 1 };
int n;
int ans = 0;
int map[MAX][MAX];
void DFS(int x, int y, int direction) {

    if (x < 1 || y < 1 || x > n || y > n) return;
    if (x == n && y == n) {
        ans += 1;
        return;
    }

    if (direction == 0) { // 가로
        int nx = x + dx[0];
        int ny = y + dy[0];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
            DFS(nx, ny, 0); // 가로 -> 가로

        nx = x + dx[2];
        ny = y + dy[2];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
        {
            if(nx -1 >= 1 && ny -1 >=1 &&nx-1 <=n && ny -1 <= n && map[nx-1][ny] == 0 && map[nx][ny-1] == 0) DFS(nx, ny, 2);
        }// 가로 -> 대각
    }
    else if (direction == 1) { // 세로
        int nx = x + dx[1];
        int ny = y + dy[1];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
            DFS(nx, ny, 1); // 세로->세로

        nx = x + dx[2];
        ny = y + dy[2];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
        {
            if (nx - 1 >= 1 && ny - 1 >= 1 && nx - 1 <= n && ny - 1 <= n && map[nx - 1][ny] == 0 && map[nx][ny - 1] == 0)
                DFS(nx, ny, 2);
        }
    }
    else if (direction == 2) { // 대각

        int nx = x + dx[0];
        int ny = y + dy[0];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
            DFS(nx, ny, 0); // 대각 -> 가로

        nx = x + dx[1];
        ny = y + dy[1];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
            DFS(nx, ny, 1); // 대각 -> 세로

        nx = x + dx[2];
        ny = y + dy[2];
        if (map[nx][ny] != 1 && nx >= 1 && ny >= 1 && nx <= n && ny <= n)
        {
            if (nx - 1 >= 1 && ny - 1 >= 1 && nx - 1 <= n && ny - 1 <= n && map[nx - 1][ny] == 0 && map[nx][ny - 1] == 0)
                DFS(nx, ny, 2);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }
    DFS(1, 2, 0);
    cout << ans << '\n';
    return 0;
}