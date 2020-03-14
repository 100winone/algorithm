/*15649 N과 M (1) 재귀 BruteForce 20200314*/
#include <stdio.h>
using namespace std;
bool c[10];
int a[10];

void go(int index, int n, int m){
    if(index == m) {
        for (int i = 0; i < m; ++i) {
            printf("%d", a[i]);
            if (i != m - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index + 1, n, m);
        c[i] = false;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    go(0, n, m);
    return 0;
}