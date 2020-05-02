/*11052 카드구매하기 DP 점화식 생각하기 어렵.. 20200502*/
#include <iostream>
#define MAX 1001
using namespace std;

int a[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    a[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + a[j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}