/*14501 퇴사 BruteForce 재귀 20200310*/
#include <stdio.h>
#include <vector>

using namespace std;
int n;
vector <int> t(17);
vector <int> p(17);
int ans = -21470000;
void go(int day, int sum){
    if(day == n + 1){
        if(ans < sum) ans = sum;
        return;
    }
    if( day > n + 1) return;
    go(day + 1, sum);
    go(day + t[day], sum + p[day]);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &t[i], &p[i]);
    }
    go(1, 0);
    printf("%d\n", ans);
    return 0;
}