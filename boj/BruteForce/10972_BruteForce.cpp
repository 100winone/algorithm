/*10972 다음 순열 BruteForce 20200309*/
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if(next_permutation(a.begin(), a.end())){
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
    } else printf("-1\n");
    printf("\n");
    return 0;
}