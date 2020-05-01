/*15988 1, 2, 3 더하기 3 DP 점화식 20200501*/
#include <iostream>

using namespace std;
int long long a[1000001];
int temp;

void dp(){
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i < 1000001; ++i) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        a[i] %= 1000000009;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp();
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        cout << a[temp] << '\n';
    }

}