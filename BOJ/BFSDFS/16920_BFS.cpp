/*16920 확장게임 BFS 20200420*/
#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

#define MAX 1001
using namespace std;

int d[MAX][MAX];
int map[MAX][MAX];
int s[10];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q[10];
queue<pair<int, int>> nextQ[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n, m, p;
    
    cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            if(str[j] == '.'){
                map[i][j] = 0;
            } else if (str[j] == '#'){
                map[i][j] = -1;
            } else {
                map[i][j] = str[j] - '0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] > 0){
                q[map[i][j]].push(make_pair(i, j));
            }
        }
    }
    while(true){
        bool check = false;
        for (int i = 1; i <= p; ++i) {
            memset(d, 0, sizeof(d));
            while(!q[i].empty()){ // 이게 라운드...로 이번 라운드 확장 확인
                check = true;
                int x, y;
                tie(x, y) = q[i].front();
                q[i].pop();
                if(d[x][y] == s[i]) {
                    nextQ[i].push(make_pair(x, y)); // 최대 이동 했으니 다음 q에다 넣어줌
                }
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(map[nx][ny] == 0){
                            d[nx][ny] = d[x][y] + 1;
                            if(d[nx][ny] <= s[i]){
                                map[nx][ny] = i;
                                q[i].push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
            q[i] = nextQ[i];
            nextQ[i] = queue<pair<int, int>>();
        }
        if(!check) break;
    }
    vector<int> res(p + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] > 0){
                res[map[i][j]] += 1;
            }
        }
    }
    for (int i = 1; i <= p; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}