/*2798 블랙잭 DFS, BruteForce 20200416 두 가지 경우 나눠서 재귀 돌림*/
#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int n, m;
int a[MAX];
int res;
void dfs(int cnt, int sum, int check){
    if(cnt == 3){
        if(sum <= m){
            res = max(res, sum);
        }
        return;
    }
    if(sum > m || check >= n) return;
    dfs(cnt + 1, sum + a[check], check + 1);

    dfs(cnt, sum, check + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << res << '\n';
    return 0;
}