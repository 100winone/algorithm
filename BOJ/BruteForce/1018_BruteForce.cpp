/*1018 체스판 다시 칠하기 BruteForce 20200409*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 50
using namespace std;
string white[8] = {{"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"}};

string black[8] = {{"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"},
                   {"BWBWBWBW"},
                   {"WBWBWBWB"}};
string map[MAX];
int n, m;
int minChess(int x, int y){
    int whiteCnt = 0;
    int blackCnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(white[i][j] != map[i + x][j + y])
                whiteCnt++;
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(black[i][j] != map[i + x][j + y])
                blackCnt++;
        }
    }
    int res = min(whiteCnt, blackCnt);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }
    int res = 2100000000;
    for (int i = 0; i <= n - 8; ++i) {
        for (int j = 0; j <= m - 8; ++j) {
            res = min(res, minChess(i, j));
        }
    }
    cout << res << '\n';
    return 0;
}