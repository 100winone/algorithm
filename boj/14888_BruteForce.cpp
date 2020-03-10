/*14888 연산자 끼워넣기 BruteForce 20200310*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int calc(vector<int> &a, vector<int> &b){
    int n = a.size();
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        if(b[i - 1] == 0){
            ans += a[i];
        } else if (b[i - 1] == 1){
            ans -= a[i];
        } else if (b[i - 1] == 2){
            ans *= a[i];
        } else {
            ans /= a[i];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<int> b;
    for (int i = 0; i < 4; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end());
    vector<int> res;
    do{
        int tmp = calc(a, b);
        res.push_back(tmp);
    } while(next_permutation(b.begin(), b.end()));
    auto ans = minmax_element(res.begin(), res.end()); // 최소최대 요소 first 최소 second 최대 auto 자료형 알아서
    printf("%d\n", *ans.second); // *로 값 찾아감
    printf("%d\n", *ans.first);
    return 0;
}