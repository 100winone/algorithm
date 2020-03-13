/*14503 로봇 청소기 Simulation 20200313*/
#include <stdio.h>
using namespace std;
int a[55][55];
int rx[] = {-1, 0, 1, 0}; // 북동남서
int ry[] = {0, 1, 0, -1};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int x, y, dir;
    scanf("%d %d %d", &x, &y, &dir);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int cnt = 0;
    while(1){
        if(a[x][y] == 0){
            a[x][y] = 2;
        }
        if(a[x + 1][y] != 0 && a[x - 1][y] != 0 && a[x][y - 1] != 0 && a[x][y + 1] != 0){
            if(a[x-rx[dir]][y-ry[dir]] == 1){
                break; // 뒤쪽 방향이 벽이라 후진도 못하는 경우
            } else {
                // 바라보는 방향을 유지한채로 한칸 후진 후 2번으로
                x -= rx[dir];
                y -= ry[dir];
            }
        } else {
            dir = (dir + 3) % 4; // 코딩이 반시계 방향으로 되어있기 때문
            if(a[x + rx[dir]][y + ry[dir]] == 0){
                x += rx[dir];
                y += ry[dir];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] == 2) {
                cnt += 1;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}

