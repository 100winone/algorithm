/*15686 치킨배달 BruteForce + DFS 20200506*/
#include <iostream>
#include <vector>
#define MAX 51
using namespace std;
int map[MAX][MAX];
int n, m;
int res = 987654321;
int cSize;
bool check[13];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> v;
int calculate(){
    int sum = 0;
    for (int i = 0; i < home.size(); ++i) {
        int x = home[i].first;
        int y = home[i].second;
        int d = 987654321;
        for (int j = 0; j < m; ++j) {
            int hx = v[j].first;
            int hy = v[j].second;
            int temp = abs(x - hx) + abs(y - hy);
            d = min(d, temp);
        }
        sum += d;
    }
    return sum;
}

void DFS(int idx, int cnt){
    if(cnt == m){
        res = min(res, calculate());
        return;
    }
    for (int i = idx; i < cSize; ++i) {
        if(check[i]) continue;
        check[i] = true;
        v.push_back(chicken[i]);
        DFS(i, cnt + 1);
        check[i] = false;
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 1) home.push_back({i, j});
            if(map[i][j] == 2) chicken.push_back({i, j});
        }
    }
    cSize = chicken.size();
    DFS(0,0);
    cout << res << '\n';
}