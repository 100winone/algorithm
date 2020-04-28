/*17406 BruteForce DFS 20200428
 * 어렵지 않은데 배열 돌리는게 진짜 귀찮!!!!
 * 이걸 알아야함*/
#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
int n, m, k;
int map[MAX][MAX];
int copyMap[MAX][MAX];
int property[7][3];
vector<int> v;
int check[7];
int dx[] = { 0, 0, 1, -1 }; // 동 서 남 북
int dy[] = { 1, -1, 0, 0 };
int res = 987654321;
void copy(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            copyMap[i][j] = map[i][j];
        }
    }
}
void rotate(int r, int c, int s){
    for (int i = 1; i <= s; ++i) {
        int last = copyMap[r - i + 1][c - i];
        int newR = r - i + 1;
        int newC = c - i;

        // 시계방향 회전
        while (r + i > newR) {
            copyMap[newR][newC] = copyMap[newR + 1][newC];
            newR++;
        }
        while (c + i > newC) {
            copyMap[newR][newC] = copyMap[newR][newC + 1];
            newC++;
        }
        while (newR > r - i) {
            copyMap[newR][newC] = copyMap[newR - 1][newC];
            newR--;
        }
        while (newC > c - i) {
            copyMap[newR][newC] = copyMap[newR][newC - 1];
            newC--;
        }
        copyMap[newR][newC] = last;
    }
}

void DFS(int cnt){
    if(cnt == k){
        copy();
        for (int i = 0; i < k; ++i) {
            rotate(property[v[i]][0], property[v[i]][1], property[v[i]][2]); // vector의 있는 순서로 보내기
        }
        for (int i = 1; i <= n; ++i) {
            int tempSum = 0;
            for (int j = 1; j <= m; ++j) {
                tempSum += copyMap[i][j];
            }
            res = min(tempSum, res);
        }
        return;
    }
    for (int i = 0; i < k; ++i) {
        if(check[i]) continue;
        v.push_back(i);
        check[i] = true;
        DFS(cnt + 1);
        v.pop_back();
        check[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k; // k는 회전 연산의 갯수
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
            copyMap[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> property[i][0] >> property[i][1] >> property[i][2]; // r, c, s
    }

    DFS(0);
    cout << res << '\n';
    return 0;
}