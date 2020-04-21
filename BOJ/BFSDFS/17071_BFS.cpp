/* 17071 숨바꼭질 BFS 20200421 시간복잡도 빡셈
 * 어려움
 * 동생의 이동방법은 항상 정해져있음*/
#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;
int d[500001][2]; // d[i][0] d[i][1] d[i]에 도착하는 가장 빠른 짝수 홀수 시간

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    d[n][0] = 0;
    while(!q.empty()){
        int x, t;
        tie(x, t) = q.front();
        q.pop();
        for (int y : {x + 1, x - 1, 2 * x}) {
            if(0 <= y && y <= 500000){
                if(d[y][1 - t] == -1){ // 방문한적 없으면
                    d[y][1 - t] = d[x][t] + 1;
                    q.push(make_pair(y, 1 - t));
                }
            }
        }
    }
    int ans = -1;
    int t = 0;
    while (true){
        k += t;
        if(k > 500000) break;
        if(d[k][t % 2] <= t){ // 수빈이 도착하는 가장 빠른 시간이 동생이 도착하는 시간보다 빠를때
            ans = t;
            break;
        }
        t += 1;
    }


    cout << ans << '\n';
    return 0;
}