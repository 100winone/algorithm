/*17071 숨바꼭질 BFS 시간초과 0.25초 20200406*/ 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dist[500001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << '0' << '\n';
        return 0;
    }
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(n); // n의 좌표 초기값으로 넣어주기
    dist[n] = 0; // 초기 거리 0 -> 이후에 1초씩 늘어나느거리로
    for (int t = 1; ; t++) {
        k += t; // k를 먼저 1초씩 늘어나는걸로 다 만들어줌
        if(k > 500000) break; // 50만보다 크면 끝내
        queue<int> nq; // 큐를 한개 더만들고 여기서 확인
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for (int y : {x + 1, x - 1, 2 * x}) { // 1초에 갈 수 있는 경우 세가지
                if(0 <= y && y <= 500000){ // y가 0보다 크고 500000보다 작으면
                    if(dist[y] != t){ // 그 좌표에 있을 때 그 시간에 한번도 도달하지 않았으면
                        nq.push(y); // y값을 nq에 넣음
                        dist[y] = t;
                    }
                }
            }
        }
        if(dist[k] == t) { // 그 거리에 있을 때랑 ... 초랑 같으면 끝내기
            cout << t << '\n';
            return 0;
        }
        q = nq;
    }
    cout << -1 << '\n';
    return 0;
}