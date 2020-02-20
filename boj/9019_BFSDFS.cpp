/*DSLR 9019번*/
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
bool check[10001];
int dist[10001];
int from[10001];
char how[10001];
queue <int> q;
int N, M;

void bfs(){

    while(!q.empty()){
        int now = q.front();
        q.pop();
        /*D 연산*/
        int next = (now * 2);
        if(next > 9999)
            next = (now * 2) % 10000;
        if(!check[next]){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'D';
        }
        /*S 연산*/
        next = (now - 1);
        if(next == -1)
            next = 9999;
        if(!check[next]){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'S';
        }
        /*L 연산*/
        next = (now % 1000) * 10 + (now / 1000);
        if(!check[next]){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'L';
        }
        /*R 연산*/
        next = (now / 10) + (now % 10) * 1000;
        if(!check[next]){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'R';
        }
    }
    string ans= "";
    while(M != N){
        ans += how[M];
        M = from[M];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%c", ans[i]);
    }
    printf("\n");
}
int main(){

    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(from, 0, sizeof(from));
        memset(how, 0 , sizeof(how));
        scanf("%d %d", &N, &M);
        check[N] = true;
        dist[N] = 0;
        from[N] = -1;
        how[N] = ' ';
        q.push(N);
        bfs();
    }
    return 0;
}
