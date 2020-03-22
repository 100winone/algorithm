/*6087 레이저 통신 BFS 20200323 recheck*/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#define MAX 101
using namespace std;
int w, h;
int answer;
char a[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void bfs(){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> h;
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 'C'){
                if(sx == -1){
                    sx = i;
                    sy = j;
                } else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    vector<vector<int>> d(h, vector<int> (w, -1)); // 2차원 벡터 초기화
    queue<pair<int, int>> q;
    d[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(a[nx][ny] == '*') break;
                if(d[nx][ny] == -1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    cout << d[ex][ey] - 1 << '\n';
    return 0;
}