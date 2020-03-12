/*14499 주사위 굴리기 Simulation 20200312*/
#include <stdio.h>
using namespace std;
int graph[21][21];
int dice[7];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main(){
    int n, m, x, y, l;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &l);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    while(l--){
        int k;
        scanf("%d", &k);
        k -= 1;
        int nx, ny;
        nx = x + dx[k];
        ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        }
        if (k == 0){ // 동
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        } else if (k == 1){ // 서
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        } else if (k == 2){ // 북
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        else { // 남
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        x = nx;
        y = ny;
        if(graph[x][y] == 0){
            graph[x][y] = dice[6];
        } else {
            dice[6] = graph[x][y];
            graph[x][y] = 0;
        }
        printf("%d\n", dice[1]);
    }
    return 0;
}

