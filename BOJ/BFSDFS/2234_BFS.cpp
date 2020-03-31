/* 2234 성곽 BFS + Bit 20200331 맞왜틀 왜틀린거임 얘?*/
#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
#define MAX 51
using namespace std;
int dx[] = {0, -1, 0, 1}; // 서 북 동 남 조건
int dy[] = {-1, 0, 1, 0};
int map[MAX][MAX]; // 첫 입력값
int d[MAX][MAX]; // 칸마다 방 번호 구하기
int room[MAX * MAX]; // 각 번방의 방의 갯수
int n, m;
int bfs(int x, int y, int rooms){
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = rooms;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt += 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(d[nx][ny] != 0) continue;
            if(map[x][y] & 1<<i) continue;
            q.push(make_pair(nx, ny));
            d[nx][ny] = rooms;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    int rooms = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(d[i][j] == 0){
                rooms += 1;
                room[rooms] = bfs(i, j, rooms);
            }
        }
    }
    cout << rooms << '\n';

    int ans = 0;
    for (int i = 0; i < rooms; ++i) {
        if (ans < room[i])
            ans = room[i];
    }
    cout << ans << '\n';

    ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = i;
            int y = j;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(d[nx][ny] == d[x][y]) continue;
                if(map[x][y] & 1 << k) {
                    if(ans < room[d[x][y]] + room[d[nx][ny]]){
                        ans = room[d[x][y]] + room[d[nx][ny]];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
