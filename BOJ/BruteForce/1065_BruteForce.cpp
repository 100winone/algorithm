/* 1065 한수 BruteForce 20200405*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[3];
    int n, k;
    cin >> n;
    if(n < 100) {
        cout << n << '\n';
        return 0;
    }
    int cnt = 99;
    for (int i = 100; i <= n; ++i) {
        memset(a, 0, sizeof(a));
        if(i == 1000) break;
        else {
            k = 0;
            int tmp = i;
            while(tmp > 0){
                a[k] = tmp % 10;
                tmp /= 10;
                k += 1;
            }
            if(a[0] - a[1] == a[1] - a[2]) cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}