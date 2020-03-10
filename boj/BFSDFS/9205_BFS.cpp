/*9205 맥주마시면서 걸어가기 BFS*/

#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 102
using namespace std;
int N;
vector <pair<int, int>> graph;
bool visited[MAX];
bool res;
bool manDis(int x, int y, int gx, int gy) {

    int dist = abs(gy - y) + abs(gx - x);

    if (dist <= 1000) {
        return true;
    }

    return false;
}

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(graph[0].first, graph[0].second));
    res = false;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int gx = graph[N + 1].first;
        int gy = graph[N + 1].second;

        if(manDis(x, y, gx, gy) == true){
            res = true;
        }
        for (int i = 1; i <= N + 1; ++i) {
            int fx = graph[i].first;
            int fy = graph[i].second;
            if(manDis(x, y, fx, fy) && (visited[i] == false)){
                visited[i] = true;
                q.push(make_pair(fx, fy));
            }
        }
    }
    if(res == true) printf("happy\n");
    else printf("sad\n");
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        memset(visited, false, sizeof(visited));
        graph.clear();

        scanf("%d", &N);

        for (int j = 0; j < N + 2; ++j) {
            int x, y;
            scanf("%d %d", &x, &y);
            graph.push_back(make_pair(x, y));
        }
        visited[0] = true;
        bfs();
    }

    return 0;
}