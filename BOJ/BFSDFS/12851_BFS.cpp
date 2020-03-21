/*12851 숨바꼭질 2 BFS, DP 20200321*/
#include <stdio.h>
#include <queue>
#define MAX 200001
using namespace std;
bool check[MAX + 1];
int dist[MAX + 1];
int cnt[MAX + 1];
queue<int> q;
void bfs(int m){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now - 1, now + 1, now * 2}){
            if(next >= 0 && next <= MAX){
                if(!check[next]){
                    q.push(next);
                    check[next] = true;
                    dist[next] = dist[now] + 1;
                    cnt[next] = cnt[now];
                } else if(dist[next] == dist[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    printf("%d\n", dist[m]);
    printf("%d\n", cnt[m]);
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    check[n] = true;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    bfs(m);
    return 0;
}