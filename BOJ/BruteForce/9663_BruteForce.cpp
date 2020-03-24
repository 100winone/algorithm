/*9663 N-Queen BruteForce BackTracking 20200324*/
#include <stdio.h>
using namespace std;
int n;
bool checkCol[15];
bool checkDig[40];
bool checkDig2[40];
bool a[15][15];
bool check(int row, int col){
    if(checkCol[col]){
        return false;
    }
    if(checkDig[row + col]){
        return false;
    }
    if(checkDig2[row - col + n]){
        return false;
    }
    return true;
}
int calc(int row){
    if(row == n) {
        return 1;
    }
    int cnt = 0;
    for (int col = 0; col < n; ++col) {
        if(check(row, col)){
            checkDig[row + col] = true; // 좌상단부터 사선 대각선
            checkDig2[row - col + n] = true; // 우상단부터 사선대각선
            checkCol[col] = true;
            a[row][col] = true;
            cnt += calc(row + 1);
            checkDig[row + col] = false; // 좌상단부터 사선 대각선
            checkDig2[row - col + n] = false; // 우상단부터 사선대각선
            checkCol[col] = false;
            a[row][col] = false;
        }
    }
    return cnt;
}
int main(){
    scanf("%d", &n);
    int ans = calc(0);
    printf("%d\n", ans);

    return 0;
}