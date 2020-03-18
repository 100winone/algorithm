/*2309 일곱 난쟁이 20200308*/

#include <stdio.h>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main(){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(sum - a[i] - a[j] == 100){
                for(int k = 0; k < n; k++){
                    if(i == k || j == k) continue;
                    printf("%d\n", a[k]);
                }
                return 0;
            }
        }
    }
    return 0;
}