/*11403 경로찾기 DFS 20200404*/
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;
bool checked[MAX];
int n;
void dfs(vector<vector<int>> &a, int startPoint){
    for (int i = 0; i < n; ++i) {
        if(a[startPoint][i] && !checked[i]){
            checked[i] = true;
            dfs(a, i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)) ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        memset(checked, false, sizeof(checked));
        dfs(a, i);
        for (int j = 0; j < n; ++j) {
            if(checked[j]){
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}