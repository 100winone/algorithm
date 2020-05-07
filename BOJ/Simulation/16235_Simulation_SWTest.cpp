/*16235 나무재테크 Simulation 20200507 
 * 문제이해하고 구현하기가 귀찮은 문제,,*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 11
using namespace std;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int n, m, k;
int year[MAX][MAX];
int flourish[MAX][MAX];
vector<int> map[MAX][MAX]; // 각 나무들의 나이 저장

void springSummer(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n ; ++j) {
            if(map[i][j].size() == 0) continue;
            int diedTree = 0;
            vector<int> v;
            sort(map[i][j].begin(), map[i][j].end());

            for (int k = 0; k < map[i][j].size(); ++k) {
                int age = map[i][j][k];
                if(flourish[i][j] >= age){
                    flourish[i][j] = flourish[i][j] - age;
                    v.push_back(age + 1);
                } else {
                    diedTree = diedTree + (age / 2);
                }
            }
            map[i][j].clear();
            for (int k = 0; k < v.size(); ++k) {
                map[i][j].push_back(v[k]);
            }
            flourish[i][j] = flourish[i][j] + diedTree;
        }
    }
}
void fall(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(map[i][j].size() == 0) continue;
            for (int k = 0; k < map[i][j].size(); ++k) {
                int age = map[i][j][k];
                if(age % 5 == 0){
                    for (int l = 0; l < 8; ++l) {
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
                            map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void winter(){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            flourish[i][j] = flourish[i][j] + year[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> year[i][j]; // 매년 추가되는 양분
            flourish[i][j] = 5; // 양분
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].push_back(z); // map[x][y]에다가 z를 넣음
    }
    for (int i = 0; i < k; ++i) {
        springSummer();
        fall();
        winter();
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res += map[i][j].size();
        }
    }
    cout << res << '\n';
}