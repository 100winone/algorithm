/*15661 링크와스타트 BruteForce 20200414*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int a[20][20];
int go(int index, vector<int> &first, vector<int> &second){
    if(index == n) {
        if(first.size() == 0) return -1;
        if(first.size() == 0) return -1;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < first.size(); ++i) {
            for (int j = 0; j < first.size(); ++j) {
                if(i == j) continue;
                t1 += a[first[i]][first[j]];
            }
        }
        for (int i = 0; i < second.size(); ++i) {
            for (int j = 0; j < second.size(); ++j) {
                if(i == j) continue;
                t2 += a[second[i]][second[j]];
            }
        }
        int diff = t1 - t2;
        if(diff < 0) diff = -diff;
        return diff;
    }
    int ans = -1;
    first.push_back(index);
    int t1 = go(index + 1, first, second);
    if(ans == -1 || t1 != -1 && ans > t1){
        ans = t1;
    }
    first.pop_back();
    second.push_back(index);
    int t2 = go(index + 1, first, second);
    if(ans == -1 || t2 != -1 && ans > t2){
        ans = t2;
    }
    second.pop_back();
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> first;
    vector<int> second;
    int res = go(0, first, second);
    cout << res << '\n';
    return 0;
}