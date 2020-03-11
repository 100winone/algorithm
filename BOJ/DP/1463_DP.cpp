/*1463 DP 1로 만들기 20200311*/
#include <stdio.h>
using namespace std;
int d[1000001];
int main(){
    int n;
    scanf("%d", &n);
    d[1] = 0;
    for (int i = 2; i <= n; ++i) {
        d[i] = d[i - 1] + 1;
        if(i % 2 == 0 && d[i] > d[i / 2] + 1){
            d[i] = d[i / 2] + 1;
        }
        if(i % 3 == 0 && d[i] > d[i / 3] + 1){
            d[i] = d[i / 3] + 1;
        }
    }
    printf("%d\n", d[n]);
    return 0;
}

