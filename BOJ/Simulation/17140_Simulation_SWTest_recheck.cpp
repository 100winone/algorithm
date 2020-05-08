/*17140 이차원배열과 연산 Simulation
 * recheck */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
int r, c, k;
int res;
int a[MAX][MAX];
int cntNum[MAX];
void solve(){
    int t = 0;
    int row = 3;
    int col = 3;

    while(1){
        if(a[r][c] == k){
            res = t;
            break;
        }
        if(t > 100){
            res = -1;
            break;
        }
        vector<int> size;
        if(row >= col){
            for (int i = 1; i <= row; ++i) {
                vector<pair<int, int>> v;
                memset(cntNum, 0, sizeof(cntNum));
                for (int j = 1; j <= col; ++j) {
                    cntNum[a[i][j]]++;
                }
                for (int j = 1; j < MAX; ++j) {
                    if(cntNum[j] == 0) continue;
                    v.push_back({cntNum[j], j});
                }
                sort(v.begin(), v.end());
                for (int j = 1; j <= col; ++j) {
                    a[i][j] = 0;
                }
                int idx = 1;
                for (int j = 0; j <v.size() ; ++j) {
                    a[i][idx++] = v[j].second;
                    a[i][idx++] = v[j].first;
                }
                idx--;
                size.push_back(idx);
            }
            sort(size.begin(), size.end());
            col = size.back();
        }
        else {
            for (int i = 1; i <= col; ++i) {
                vector<pair<int, int>> v;
                memset(cntNum, 0, sizeof(cntNum));
                for (int j = 1; j <= row ; ++j) {
                    cntNum[a[j][i]]++;
                }
                for (int j = 1; j < MAX; ++j) {
                    if(cntNum[j] != 0){
                        v.push_back({cntNum[j], j});
                    }
                }
                sort(v.begin(), v.end());
                for (int j = 1; j <= row ; ++j) {
                    a[j][i] = 0;
                }
                int idx = 1;
                for (int j = 0; j < v.size(); ++j) {
                    a[idx++][i] = v[j].second;
                    a[idx++][i] = v[j].first;
                }
                idx--;
                size.push_back(idx);
            }
            sort(size.begin(), size.end());
            row = size.back();
        }
        t++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> a[i][j];
        }
    }
    if(a[r][c] == k){
        res = 0;
        cout << res << '\n';
        return 0;
    }
    solve();
    cout << res << '\n';
    return 0;
}