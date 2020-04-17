/*15684 사다리조작 DFS + BruteFrce 20200417*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, h;
int ladderCnt;
bool ladder[31][11];
bool flag;

void DFS(int x, int cnt){
    if(flag)
        return;

    if(ladderCnt == cnt){
        bool possible = true;
        for (int i = 1; i <= n; ++i) {
            int row = i;
            for (int j = 0; j < h; ++j) {
                if(ladder[j][row]){
                    row += 1;
                } else if (row > 1 && ladder[j][row - 1]){
                    row -= 1;
                }
            }
            if(i != row){
                possible = false;
                break;
            }
        }
        if(possible)
            flag = true;
        return;
    }
    for (int i = x; i < h; ++i) { // 가로선 총 길이
        for (int j = 1; j < n; ++j) { // n 세로 선 총 갯수
            // 가로선이 연속하거나 접하지 않게 하는 규칙
            if(!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]){
                ladder[i][j] = true;
                DFS(i, cnt + 1);
                ladder[i][j] = false;
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ladder[x - 1][y] = true; // x 번째 h선 높이에 연결된 y ~ y+1 좌표
    }
    for (int i = 0; i <= 3; ++i) {
        ladderCnt = i;
        DFS(0, 0); // 맨 위부터 탐색
        if(flag){
            cout << ladderCnt << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}