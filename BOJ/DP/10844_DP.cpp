/*10844 쉬운 계단 수 DP 20200504
 * 점화식 어려운편*/
#include <iostream>
#define MAX 101
using namespace std;
int n;
long long res;
long long dp[MAX][11];

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= 9; ++i) { // 한 자리수는 한개
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) { // 0에서 9로 끝나는 경우
            if(j == 0) dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            else if(j == 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000;
        }
    }
    for (int i = 0; i < 10; ++i) {
        res += dp[n][i];
    }
    cout << res % 1000000000<< '\n';
    return 0;
}