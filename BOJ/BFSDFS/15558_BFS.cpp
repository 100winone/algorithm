/*15558 점프게임 BFS 20200323*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
bool check[2][100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    vector<string> a(2);
    for (int i = 0; i < 2; ++i) {
        cin >> a[i];
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q.size(); ++j) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int nx[] = {x, x, !x};
            int ny[] = {y - 1, y + 1, y + k};
            for (int k = 0; k < 3; ++k) {
                if(ny[k] >= n){
                    cout << "1\n";
                    return 0;
                }
                if(ny[k] <= i || check[nx[k]][ny[k]] || a[nx[k]][ny[k]] == '0') continue;
                q.push(make_pair(nx[k], ny[k]));
                check[nx[k]][ny[k]] = true;
            }
        }
    }
    cout << "0\n";
    return 0;
}