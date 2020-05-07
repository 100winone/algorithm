/*11057 DP 오르막 수 20200507 
 * 점화식 생각하기 어려움*/
#include <iostream>
#define MAX 1001
using namespace std;
int dp[MAX][10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) { // 자릿수
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = dp[i][j] + dp[i - 1][k];
                dp[i][j] = dp[i][j] % 10007;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        res += dp[n][i];
    }
    cout << res % 10007 << '\n';
    return 0;
}