/*15683 감시 DFS + BruteForce 20200416
 * 내가 여태까지 풀어본 문제중에 가장이해가 안가서
 *  https://jaimemin.tistory.com/1070 참조했음
 *  그래도 어렵습니다...
 *  다시 한 번 풀어볼 것
 * */

#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;

typedef struct {
    int x, y;
}DirXY;
DirXY dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m;
int res;
int matrix[8][8];
int copyMatrix[8][8];
vector<pair<int, int>> cctv;
vector<int> angle;
bool check[8][8][4]; // 마지막은 방향
void copy(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            copyMatrix[i][j] = matrix[i][j];
        }
    }
}
int countBlind(){
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(copyMatrix[i][j] == 0)
                res += 1;
        }
    }
    return res;
}
void DFS(int cnt){
    if(cnt == cctv.size()){
        for (int i = 0; i < angle.size(); ++i) {
            int x = cctv[i].first;
            int y = cctv[i].second;
            for (int j = 0; j < 4; ++j) {
                if(check[x][y][j]){
                    // 각도 바꾸고 비추기
                    int nextX = x + dir[(angle[i] + j) % 4].x;
                    int nextY = y + dir[(angle[i] + j) % 4].y;
                    //cout << y << " " << x << " " << angle[i] << " " << j << "\n";
                    while(true){
                        if(copyMatrix[nextX][nextY] == 6)
                            break;
                        if(!(0 <= nextX && nextX < n && 0 <= nextY && nextY < m))
                            break;
                        if(copyMatrix[nextX][nextY] == 0){ // 사각지대가 아니게 되면
                            copyMatrix[nextX][nextY] = -1;
                        }
                        nextX += dir[(angle[i] + j) % 4].x;
                        nextY += dir[(angle[i] + j) % 4].y;
                    }
                }
            }
        }
        res = min(res, countBlind());
        copy();
        return;
    }
    for (int i = 0; i < 4; ++i) {
        angle.push_back(i);
        DFS(cnt + 1);
        angle.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            if (1 <= matrix[i][j] && matrix[i][j] <= 5) {
                cctv.push_back(make_pair(i, j));
            }
            switch (matrix[i][j]) {
                case 1:
                    check[i][j][0] = true;
                    break;
                case 2:
                    check[i][j][0] = true;
                    check[i][j][2] = true;
                    break;
                case 3:
                    check[i][j][0] = true;
                    check[i][j][3] = true;
                    break;
                case 4:
                    check[i][j][0] = true;
                    check[i][j][2] = true;
                    check[i][j][3] = true;
                    break;
                case 5:
                    check[i][j][0] = true;
                    check[i][j][1] = true;
                    check[i][j][2] = true;
                    check[i][j][3] = true;
                    break;
            }
        }
    }
    res = 2100000000;
    copy();
    DFS(0);
    cout << res << '\n';
    return 0;
}