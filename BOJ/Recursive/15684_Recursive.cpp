#include <iostream>
using namespace std;
int graph[31][11];
int N, M, H;
int answer = 987654321;
bool isValidLadder(){
    for (int i = 1; i <= N; ++i) {
        int curPos = i;
        for (int j = 1; j <= H; ++j) {
            if(graph[j][curPos] == 1) curPos++;
            else if(graph[j][curPos - 1] == 1) curPos--;
        }
        if(i != curPos) return false;
    }
    return true;
}
void recur(int ladderCnt, int x, int y){
    if(ladderCnt >= answer){
        return;
    }
    if(isValidLadder()){
        answer = ladderCnt;
        return;
    }
    if(ladderCnt == 3){
        return;
    }
    for (int i = y; i <= H; ++i) {
        for (int j = x; j < N; ++j) {
            if(graph[i][j] == 1){
                j++;
                continue;
            }
            graph[i][j] = 1;
            recur(ladderCnt + 1, j + 2, i);
            graph[i][j] = 0;
        }
        x = 1;
    }
}
int main(){
    /* n - 세로선 갯수
     * m - 가로선 갯수
     * h - 가로선을 놓을 수 있는 위치의 갯수
     * */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    recur(0, 1, 1);
    if(answer > 3) cout << -1 << '\n';
    else cout << answer << '\n';
    return 0;
}