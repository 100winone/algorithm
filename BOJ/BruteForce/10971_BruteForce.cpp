/*10971 BruteForce 외판원 순회 20200310*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[11][11];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = i;
    }
    int ans = 2147400000;

    do{
        // if (d[0] != 1) break; 이렇게 하고 d.begin() 만 해줘도된다. n이줄어듦 N이 몇이든 1번도시는 항상 존재
        // N!으로 해결가능
        bool check = true;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            if(a[d[i]][d[i + 1]] == 0) check = false;
            else sum += a[d[i]][d[i + 1]];
        }
        if(check && a[d[n - 1]][d[0]] != 0){
            sum += a[d[n - 1]][d[0]];
            if(ans > sum) ans = sum;
        }
    } while(next_permutation(d.begin(), d.end())); // d.begin() 을 d.begin() + 1로 시작점을 고정해줘도 된다 시간 복잡도 줄어듦

    printf("%d\n", ans);
    return 0;
}