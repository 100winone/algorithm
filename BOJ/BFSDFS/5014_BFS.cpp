/*5014 스타트링크 BFS 20200326*/
#include <stdio.h>
#include <algorithm>
#include <queue>
#define MAX 1000001
using namespace std;
int F, S, G, U, D;
queue <int> q;
bool check[MAX];
int dist[MAX];
void bfs(){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now + U <= F && !check[now + U]){
            dist[now + U] = dist[now] + 1;
            check[now + U] = true;
            q.push(now + U);
        }
        if(now - D >= 1 && !check[now - D]){
            dist[now - D] = dist[now] + 1;
            check[now - D] = true;
            q.push(now - D);
        }
    }
    if(check[G]){
        printf("%d\n", dist[G]);
    } else {
        printf("use the stairs\n");
    }
}
int main(){
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    q.push(S);
    check[S] = true;
    bfs();
    return 0;
}