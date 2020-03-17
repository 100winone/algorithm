/*11724 연결 요소의 개수 DFS 20200317*/
#include <stdio.h>
#include <vector>
using namespace std;

vector <int> a[1001];
bool checked[1001];
void dfs(int node){
    checked[node] = true;
    for (int i = 0; i < a[node].size(); ++i) {
        int next = a[node][i];
        if(checked[next] == false){
            dfs(next);
        }
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if(checked[i] == false){
            dfs(i);
            components += 1;
        }
    }
    printf("%d\n", components);
    return 0;
}