#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(x,n)  for(int x=0;x<(n);x++)

typedef struct Tom{
    int x, y, z, d;
    Tom(int Z, int X, int Y, int D) : z(Z), x(X), y(Y), d(D) {}
};

int m,n,h;
int arr[101][101][101];
bool visit[101][101][101];
int dir[6][3] = {{-1,0,0},{0,1,0},{1,0,0},{0,-1,0},{0,0,1},{0,0,-1}};
queue<Tom> q;
int ans;

bool isRange(int z, int x, int y){
    if(z<0 || z>=h || x<0 || x>=n || y<0 || y>=m || visit[z][x][y]) return false;
    return true;
}

void bfs(){
    while(!q.empty()){
        Tom cur = q.front(); q.pop();

        FOR(i,6){
            int nextZ = cur.z + dir[i][2], nextX = cur.x + dir[i][0], nextY = cur.y + dir[i][1];
            if(!isRange(nextZ,nextX,nextY) || arr[nextZ][nextX][nextY] != 0) continue;

            q.push(Tom(nextZ,nextX,nextY,cur.d+1));
            visit[nextZ][nextX][nextY] = true;
            arr[nextZ][nextX][nextY] = cur.d+1;
            ans = max(ans,cur.d+1);
        }
    }
}

int main() {
    cin >> m >> n >> h;


    FOR(k,h){
        FOR(i,n){
            FOR(j,m){
                cin >> arr[k][i][j];
                if(arr[k][i][j] == 1){
                    q.push(Tom(k,i,j,0));
                    visit[k][i][j] = true;
                }
            }
        }
    }

    bfs();

    FOR(k,h){
        FOR(i,n){
            FOR(j,m){
                if(arr[k][i][j] == 0){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << ans;
}