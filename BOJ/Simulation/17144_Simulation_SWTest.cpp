/*17144 미세먼지 안녕! Simulation 20200430 
 * 진짜 디버깅 힘든 시뮬*/
#include <iostream>
#define MAX 51
using namespace std;
int res;
int r, c, t;
int map[MAX][MAX];
int copyMap[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int locate[2];
using namespace std;
void copy(int A[][MAX], int B[][MAX]) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            A[i][j] = B[i][j];
        }
    }
}

void spreadDust() {
    copy(copyMap, map);
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if(map[i][j] == -1 || map[i][j] == 0) continue;
            int value = map[i][j] / 5;
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx > 0 && ny > 0 && nx <= r && ny <= c)
                {
                    if (map[nx][ny] != -1)
                    {
                        copyMap[nx][ny] = copyMap[nx][ny] + value;
                        cnt++;
                    }
                }
            }
            copyMap[i][j] = copyMap[i][j] - (value * cnt);
        }
    }
    copy(map, copyMap);
}

void move(){
    int cleanerX = locate[0]; // 3
    int x = cleanerX - 1; // 2
    int y = 1; // 1
    while(x > 1){
        map[x][y] = map[x - 1][y];
        x--;
    }
    // x = 1 , y = 1
    while(y < c){
        map[x][y] = map[x][y + 1];
        y++;
    }
    // x = 1, y = 8
    while(x < cleanerX){
        map[x][y] = map[x + 1][y];
        x++;
    }
    //x = 3, y = 8
    while(y > 2){
        map[x][y] = map[x][y - 1];
        y--;
    }
    map[cleanerX][2] = 0;

    /*시계로 돌릴 경우*/
    cleanerX = locate[1]; // 4
    x = cleanerX + 1; // 5
    y = 1;
    while(x < r){ // r = 7
        map[x][y] = map[x + 1][y];
        x++;
    }
//     x = 7, y = 1
    while(y < c){ // c = 8
        map[x][y] = map[x][y + 1];
        y++;
    }
//     x = 7, y = 8
    while(x > cleanerX){
        map[x][y] = map[x - 1][y];
        x--;
    }
//    // x = 4, y = 8
    while(y > 2){
        map[x][y] = map[x][y - 1];
        y--;
    }
    map[cleanerX][2] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> t;
    int cnt = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                locate[cnt++] = i; // v[0]이 위에 공기청정기 v[1]이 아래 공기청정기
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        spreadDust();
        move();
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if(map[i][j] == -1) continue;
            res += map[i][j];
        }
    }
    cout << res << '\n';
    return 0;
}

