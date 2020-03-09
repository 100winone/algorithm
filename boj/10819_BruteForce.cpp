/*10819 BruteForce 차이를 최대로 20200309*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int calculate(vector<int> &a){
    int sum = 0;
    for (int i = 1; i < a.size(); ++i) {
        sum += abs(a[i - 1] - a[i]);
    }
    return sum;
}
int main() {
    int n, sum = 0;
    scanf("%d", &n); // 9까지는 순열 BruteForce로 가능
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end()); // vector는 begin과 end로 sort

    do{
        int tmp = calculate(a);
        sum = max(sum, tmp); // 큰 값 구하기
    } while(next_permutation(a.begin(), a.end()));

    printf("%d\n", sum);
    return 0;
}