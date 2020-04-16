#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int res;
bool cmp(int a, int b){ // 내림차순
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int n, k;

    vector<int> v;
    for (int i = 0; i < t; ++i) {
        v.clear();
        string str;
        cin >> n >> k;
        cin >> str;
        int cntPerNum = n / 4; // n이 12일때는 3
        for (int i = 0; i < cntPerNum; ++i) {
            int temp;
            int sum = 0;
            int exp = cntPerNum; // ex)3
            for (int j = 0; j < n; ++j) {
                exp -= 1;
                if(str[j] <= '9'){
                    temp = (str[j] - '0') * pow(16, exp);
                } else{
                    temp = (str[j] - 55) * pow(16, exp);
                }
                sum += temp;
                if(exp == 0){
                    v.push_back(sum);
                    sum = 0;
                    exp = cntPerNum;
                }
            }
            temp = str[n - 1];
            for (int l = n - 1; l > 0; --l) {
                str[l] = str[l - 1];
            }
            str[0] = temp;
        }
        sort(v.begin(), v.end(), cmp);
        int lastCnt = 0;
        int lasTemp = 0;
        for (int l = 0; l < v.size(); ++l) {
            if(lasTemp == v[l]) continue;
            lastCnt += 1;
            if(lastCnt == k) {
                res = v[l];
                break;
            }
            lasTemp = v[l];
        }
        cout << '#' << i + 1 << ' ' << res << '\n';
    }
    return 0;
}