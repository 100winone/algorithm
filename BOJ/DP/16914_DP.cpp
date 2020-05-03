/*16194 카드 구매하기2 DP , 최소구하는 문제라 헷갈림*/
#include <iostream>
#define MAX 1001
using namespace std;

int a[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a[0] = 0;
    dp[0] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = 10001; // 최솟값 구하는 것이므로 초기화 해줘야함
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + a[j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}