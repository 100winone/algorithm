/*3190 뱀 Simulation 20200330 hard*/
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
int dx[] = {0, 1, 0, -1}; // 동 남 서 북
int dy[] = {1, 0, -1, 0};
int map[MAX][MAX];
bool apple[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        apple[x - 1][y - 1] = true;
    }
    memset(map, -1, sizeof(map));
    int x = 0;
    int y = 0;
    int dir = 0;
    int len = 1;
    map[x][y] = 0;
    cin >> k;
    int now = 0;
    for (int i = 0; i <= k; ++i) {
        int t = n * n + 1;
        char ch;
        if(i < k){
            cin >> t >> ch;
        }
        while(now < t){
            now += 1;
            x += dx[dir];
            y += dy[dir];
            if(x < 0 || x >= n || y < 0 || y >= n){
                cout << now << '\n';
                return 0;
            }
            if(apple[x][y]){
                apple[x][y] = false;
                len += 1;
            }
            if(map[x][y] != -1 && now - map[x][y] <= len){
                cout << now << '\n';
                return 0;
            }
            map[x][y] = now;
        }
        if(ch == 'L'){
            dir = (dir + 3) % 4;
        } else {
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}