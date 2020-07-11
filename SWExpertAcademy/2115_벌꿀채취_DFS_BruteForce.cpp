/* SW Expert 2115 벌꿀채취 BruteForce + DFS, 가지치기*/
#include <iostream>
#define MAX 11
using namespace std;
int N, M, C;

int res;
int honeyPot[MAX][MAX];
void DFS(int x, int y, int sum, int cnt, int price){
    if(sum > C) return;
    res = max(res, price);
    if(cnt == M) return;

    // M 개 뽑는과정
    DFS(x, y + 1, sum + honeyPot[x][y], cnt + 1, price + honeyPot[x][y] * honeyPot[x][y]);
    DFS(x, y + 1, sum, cnt + 1, price); // 뽑든 안뽑든 해야하니까
}
int calculate(int x, int y){
    // 기준 값 1번 벌꿀러의 좌표
    res = 0;
    DFS(x, y, 0, 0, 0);
    int price_a = res;
    int price_b = 0;
    int j = y + M;
    for (int i = x; i < N; ++i) {
        for (; j < N - M + 1 ; ++j) {
            res = 0;
            DFS(i, j, 0, 0, 0);
            price_b = max(res, price_b);
        }
        j = 0;
    }
    return price_a + price_b;
}
int main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; ++t) {
        int max_profit = 0;
        cin >> N >> M >> C;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> honeyPot[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N - M + 1; ++j) {
                max_profit = max(max_profit, calculate(i, j));  // x, y 좌표 같이
            }
        }
        cout << '#' << t << ' ' << max_profit << '\n';
    }
    return 0;
}