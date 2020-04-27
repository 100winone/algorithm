/*17281 BruteForce DFS 야구 20200427 Gold 4
 * 어렵지는 않은데 구현하기 귀찮음 생각해야할 것들이 많음
 * 삼성 기출*/
#include <iostream>
#include <cstring>
#define MAX 51
#define PLAYER_NUM 10
using namespace std;

int game[MAX][PLAYER_NUM]; // 몇번째 이닝의 몇번선수의 능력치
int order[PLAYER_NUM]; // 타석 순서
bool check[PLAYER_NUM]; // 이미 그 타석의 타자를 뽑았나
int n, ans;

void play(){
    int startPlayer = 1;
    int base[4];
    int score = 0;
    for (int i = 1; i <= n; ++i) {
        int outCnt = 0;
        bool nextInning = false;
        memset(base, 0, sizeof(base));

        while(1){
            for (int j = startPlayer; j < PLAYER_NUM; ++j) {
                int player = game[i][order[j]];
                if(player == 0) {
                    outCnt += 1;
                } else if (player == 1){
                    for (int k = 3; k >= 1; --k) {
                        if(base[k] == 1){
                            if(k == 3) {
                                base[k] = 0;
                                score++;
                            } else{
                                base[k + 1] = 1;
                                base[k] = 0;
                            }
                        }
                    }
                    base[1] = 1;
                } else if (player == 2){
                    for (int k = 3; k >= 1; --k) {
                        if(base[k] == 1){
                            if(k >= 2){
                                base[k] = 0;
                                score++;
                            } else{
                                base[k + 2] = 1;
                                base[k] = 0;
                            }
                        }
                    }
                    base[2] = 1;
                } else if (player == 3){
                    for (int k = 3; k >= 1; --k) {
                        if(base[k] == 1){
                            base[k] = 0;
                            score++;
                        }
                    }
                    base[3] = 1;
                } else { // 홈런
                    for (int k = 3; k >= 1; --k) {
                        if(base[k] == 1){
                            base[k] = 0;
                            score++;
                        }
                    }
                    score++;
                }
                if(outCnt == 3){
                    startPlayer = j + 1;
                    if(startPlayer == PLAYER_NUM) {
                        startPlayer = 1; // 10번타자는 없으니까 1번타자로 바꿔주기
                    }
                    nextInning = true;
                    break;
                }
            }
            if(nextInning == true) break;
            startPlayer = 1; // 얘는 이닝이 끝나지 않은 상황에서 해주는 거
        }
    }
    ans = max(ans, score);
}
void DFS(int cnt){
    if(cnt == PLAYER_NUM){
        play();
        return;
    }
    /*순열로 구현*/
    for (int i = 1; i < PLAYER_NUM; ++i) {
        if(check[i]) continue;
        check[i] = true;
        order[i] = cnt; // 맨 처음.. i번타자는 cnt번등번호
        DFS(cnt + 1);
        check[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < PLAYER_NUM; ++j) {
            cin >> game[i][j];
        }
    }
    check[4] = true;
    order[4] = 1; // 4번 타석의 타자는 등번호 1
    DFS(2);
    cout << ans << '\n';
    return 0;
}