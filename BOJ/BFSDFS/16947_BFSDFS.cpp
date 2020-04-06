/*16947 서울 지하철 2호선 BFS + DFS 20200406 very hard*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 3000
using namespace std;
vector<int> a[MAX]; // DFS 양방향 간선 그래프 할때 주로 선언
bool isCycleStation[MAX];
bool checked[MAX];
int n;

void dfs(int start, int cur, int cnt){ // dfs로 순환인지 확인
    if(start == cur && cnt >= 2){ // cnt가 2 이상이면 양방향에 들어왔는지 확인할 수 있음
        isCycleStation[cur] = true;
        return;
    }
    checked[cur] = true; // 현 위치를 확인하고
    for (int i = 0; i < a[cur].size(); ++i) { // 현재 위치의 사이즈만큼 간선을 돌아서 DFS
        int next = a[cur][i]; // 
        if(!checked[next]) {
            dfs(start, next, cnt + 1); 
        }
        if(start == next && cnt >= 2) { 
            dfs(start, next, cnt);
        }
    }
}
int bfs(int startPoint){
    queue<pair<int, int>> q;
    bool bfsCheck[MAX] = {false, };
    q.push(make_pair(startPoint, 0));
    bfsCheck[startPoint] = true; 

    while(!q.empty()){
        int now = q.front().first;
        int cntFromCycle = q.front().second; // 순환에서 벗어난 갯수
        q.pop();
        if (isCycleStation[now]){
            return cntFromCycle;
        }
        for (int i = 0; i < a[now].size(); ++i) {
            int next = a[now][i];
            if(bfsCheck[next]) continue;
            q.push(make_pair(next, cntFromCycle + 1));
            bfsCheck[next] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        memset(checked, false, sizeof(checked));
        dfs(i, i, 0);
    }
    for (int i = 0; i < n; ++i) { // 다 돌면서 BFS
        if(isCycleStation[i]){ // 그게 순환에 있는 애면 0 출력
            cout << 0 << ' ';
            continue;
        }
            cout << bfs(i) << ' ';

    }
    return 0;
}