/* 15685 드래곤커브 Simulation SW 기출 20200504 , 이런거 할때 항상 규칙을 찾아보는 게 중요하다.
 * 규칙 찾는거 은근 까다로움
 * */
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n;
int x, y, d, g;
int cnt;
int map[MAX][MAX];
vector<int> v;

void simulation(){
    int sizeV = v.size();
    for (int i = sizeV - 1; i >= 0; --i) {
        int nextD = (v[i] + 1) % 4;
        v.push_back(nextD);
        x = x + dx[nextD];
        y = y + dy[nextD];
        map[x][y] = 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> d >> g; // d는 방향 g는 세대
        v.clear();
        map[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        map[x][y] = 1;
        v.push_back(d);
        for (int j = 0; j < g; ++j) {
            simulation();
        }
    }
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if(map[i][j] == 1 && map[i + 1][j] == 1){
                if (map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
                    cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}