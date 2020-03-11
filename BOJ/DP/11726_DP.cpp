/*11726 DP 2xN 타일링 20200311*/
#include <stdio.h>
using namespace std;
int d[1001];
int main(){
    int n;
    scanf("%d", &n);
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i] = d[i - 1] + d[i - 2];
        d[i] %= 10007;
    }
    printf("%d\n", d[n]);
    return 0;
}

