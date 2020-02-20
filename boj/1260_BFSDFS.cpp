#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

void dfs(int v, vector<int> graph[], bool check[]) {
    check[v] = true;
    printf("%d ", v);
    for (int i = 0; i < graph[v].size(); i++) {
        if (!check[graph[v][i]]) dfs(graph[v][i], graph, check);
    }
}

void bfs(int v, vector<int> graph[], bool check[]) {
    queue<int> q;
    q.push(v);
    check[v] = true;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        printf("%d ", next);
        for (int i = 0; i < graph[next].size(); ++i) {
            if(!check[graph[next][i]]) {
                q.push(graph[next][i]);
                check[graph[next][i]] = true;
            }
        }
    }

}

int main() {
    int n, m, v, x, y;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &v);

    vector<int> graph[n + 1];
    bool check[n + 1];

    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v, graph, check);
    printf("\n");
    memset(check, false, sizeof(check));
    bfs(v, graph, check);
    return 0;
}
