/*13913 숨바꼭질 BFS*/

#include <cstdio>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 100001
using namespace std;
int dist[100001];
bool check[100001];
deque<int> q;
vector<int> path;
int from[MAX];
int N, M;
void bfs(){
    while(!q.empty()){
        int now = q.front();
        q.pop_front();
        int next;
        if(now * 2 < MAX){
            if(!check[now * 2]){
                next = now * 2;
                q.push_back(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
            }
        }
        if((now - 1 >= 0) && (check[now - 1] == false)){
            next = now - 1;
            q.push_back(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
        }
        if(now + 1 < MAX){
            if(!check[now + 1]){
                next = now + 1;
                q.push_back(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
            }
        }
    }
    printf("%d\n", dist[M]);
    int trace = M;
    while (trace != N) {
        path.push_back(trace);
        trace = from[trace];
    }
    reverse(path.begin(), path.end());
    printf("%d ", N);
    for (int i = 0; i < path.size(); i++)
        printf("%d ", path[i]);
}

int main(){
    scanf("%d %d", &N, &M);
    check[N] = true;
    dist[N] = 0;
    q.push_back(N);
    bfs();
    return 0;
}
