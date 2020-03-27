/*13458 시험감독 Greedy 20200327*/
#include <stdio.h>
using namespace std;
int main(){
    int n;
    int b, c;
    scanf("%d", &n);
    long long cnt = n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &b, &c);
    for (int i = 0; i < n; ++i) {
        a[i] -= b;
        if (a[i] <= 0) continue;
        if (a[i] % c == 0) {
            cnt += a[i] / c;
            continue;
        }
        else {
            cnt += (a[i] / c + 1);
        }
    }
    printf("%lld\n", cnt);
    return 0;
}