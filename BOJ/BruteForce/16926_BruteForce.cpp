/*16926 배열돌리기 BruteForce*/
#include <iostream>
#define MAX 301
using namespace std;
int n, m, r;
int map[MAX][MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }
    int rotate = min(m, n);
    rotate /= 2;
    for (int i = 0; i < r; ++i) {
        int tempN = n, tempM = m;
        for (int j = 1; j <= rotate; ++j) {
            int x = j;
            int y = j;
            int temp = map[x][y];
            while(y < tempM){
                map[x][y] = map[x][y + 1];
                y++;
            }
            while(x < tempN){
                map[x][y] = map[x + 1][y];
                x++;
            }
            while(y > j){
                map[x][y] = map[x][y - 1];
                y--;
            }
            while(x > j){
                map[x][y] = map[x - 1][y];
                x--;
            }
            map[x + 1][y] = temp;
            tempN--;
            tempM--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << map[i][j] <<' ';
        }
        cout << '\n';
    }
    return 0;
}