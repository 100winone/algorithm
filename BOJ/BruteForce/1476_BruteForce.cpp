/*1476 날짜 계산 20200308*/

#include <stdio.h>
using namespace std;

int main(){
    int E, S, M;
    int e = 1, s = 1, m = 1;
    scanf("%d %d %d", &E, &S, &M);
    for (int i = 1; ; ++i) {
        if(E == e && S == s && M == m){
            printf("%d\n", i);
            break;
        }
        e += 1;
        s += 1;
        m += 1;
        if(e == 16) e = 1;
        if(s == 29) s = 1;
        if(m == 20) m = 1;
    }
    return 0;
}