/*17136 색종이 붙이기 BruteForce_DFS_Simulation 20200425 역테 기출*/
/*처음인덱스부터 돌면서 5*5 4*4 이런식으로 다 돌아보게 하기. 백트래킹 가지치면서 가야함*/
#include <iostream>
#define MAX 10
using namespace std;
int res = 2147000000;
int cnt;
int map[MAX][MAX];
int paperCnt[6] = {0, 5, 5, 5, 5, 5};
void DFS(int x, int y){
    // 각 열 다 확인했으면 다음행으로
    if(y == MAX){
        DFS(x + 1, 0);
        return;
    }
    // 모든 칸 확인했으면 계산하기
    if(x == MAX){
        res = min(res, cnt);
        return ;
    }
    // 0 이면 밑에 볼 필요 없으므로 다음으로 넘겨줌
    if(map[x][y] == 0){
        DFS(x, y + 1);
        return;
    }
    for (int i = 5; i >= 1 ; --i) {
        if(paperCnt[i] == 0 || x + i > MAX || y + i > MAX) continue; // 밑에서 더하는 i는 4까지이므로 여기서는 5까지
        // 색종이 길이만큼 비교하면서 돌리기
        bool flag = true;
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < i; ++k) {
                if(map[x + j][y + k] == 0){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) continue;
        /* 색종이 덮었으니 0으로 바꿔주기*/
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < i; ++k) {
                map[x + j][y + k] = 0;
            }
        }
        paperCnt[i] -= 1;
        cnt++;
        DFS(x, y + i);

        /*여기서 덮지 않을 경우로 돌려야하니까 1로 채워주기*/
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < i; ++k) {
                map[x + j][y + k] = 1;
            }
        }
        paperCnt[i] += 1;
        cnt--;
    }
}

int main(){
    int zeroChk = 0;
    bool flag = false;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            cin >> map[i][j];
        }
    }

    DFS(0, 0);
    if(res == 2147000000){
        cout << -1 << '\n';
        return 0;
    }
    cout << res << '\n';
    return 0;
}