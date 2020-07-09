/* 1022 Simulation 소용돌이 예쁘게 출력하기 20200709*/
#include <iostream>

using namespace std;
int square[50][5];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main() {
    int x = 0;
    int y = 0;
    int len = 0; // 처음 길이
    int dir = -1; // 방향
    int pickedCnt = 1; // 뽑힌갯수
    int r1, c1, r2, c2;
    int putNum = 1; // 넣을 숫자
    int maxInput = 0; // 최대값
    cin >> r1 >> c1 >> r2 >> c2;
    int rowSize = r2 - r1 + 1;
    int colSize = c2 - c1 + 1;
    int totalCnt = rowSize * colSize;


    if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
        square[x - r1][y - c1] = putNum;
        pickedCnt++;
    }

    while (pickedCnt <= totalCnt) {
        dir = (dir + 1) % 4;
        if (dir == 0 || dir == 2) len++;
        for (int i = 0; i < len; ++i) {
            putNum++;
            x += dx[dir];
            y += dy[dir];
            if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
                square[x - r1][y - c1] = putNum;
                pickedCnt++;
                maxInput = putNum;
            }
        }
    }
    int maxLen = to_string(maxInput).size();
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            for (int k = 0; k < maxLen - to_string(square[i][j]).size(); ++k) {
                cout << ' ';
            }
            cout << square[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
