/*17471 게리맨더링 BruteForce DFS BFS IDE에서는 잘 되는 컴파일에러..*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 11

using namespace std;
int population[MAX]; // 인구 수
bool connection[MAX][MAX]; // 연결관계
bool select[MAX];
bool checked[MAX];
int n, res = 987654321;

bool checkBFS(vector<int> v, bool isBool){
    memset(checked, 0, sizeof(checked));
    queue<int> q;
    q.push(v[0]);
    checked[v[0]] = true;
    int cnt = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if(connection[x][i] == true && !checked[i] && select[i] == isBool){
                checked[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }
    if(v.size() == cnt) return true;
    return false;
}
bool isValid(){
    /*선거구의 포함된 구역 갯수가 1개이상인지, 선거구에 포함된 구역들 끼리 연결되었는지 체크*/
    vector<int> a, b;
    for (int i = 1; i <= n; ++i) {
        if(select[i]) a.push_back(i); // 조합으로 A와 B로 나눔
        else b.push_back(i);
    }
    if(a.size() == 0 || b.size() == 0) return false;


    if(!checkBFS(a, true)) return false;
    if(!checkBFS(b, false)) return false;

    return true;
}
/*조합으로 구현*/
void DFS(int idx, int cnt){
    if(cnt >= 1){
        if(isValid() == true){
            int populationA = 0;
            int populationB = 0;
            int diff;
            for (int i = 1; i <= n; ++i) {
                if(select[i] == true) {
                    populationA += population[i];
                } else {
                    populationB += population[i];
                }
            }
            diff = abs(populationA - populationB);
            if(res > diff) res = diff;
        }
    }
    for (int i = idx; i <= n; ++i) {
        if(select[i]) continue;
        select[i] = true;
        DFS(i, cnt + 1);
        select[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> population[i];
    }
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int k;
            cin >> k;
            connection[i][k] = true;
            connection[k][i] = true;
        }
    }
    DFS(1, 0);
    if(res == 987654321) cout << -1 << '\n';
    else cout << res << '\n';
    return 0;
}