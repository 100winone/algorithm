/*1697 숨바꼭질 BFS 20200318*/
#include <stdio.h>
#include <queue>
#define MAX 200001
using namespace std;
bool checked[MAX];
int d[MAX];
queue<int> q;
void bfs(int n, int k){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now - 1 >= 0){
            if(!checked[now - 1]){
                q.push(now - 1);
                checked[now - 1] = true;
                d[now - 1] = d[now] + 1;
            }
        }
        if(now + 1 < MAX){
            if(!checked[now + 1]){
                q.push(now + 1);
                checked[now + 1] = true;
                d[now + 1] = d[now] + 1;
            }
        }
        if(now * 2 < MAX){
            if(!checked[now * 2]){
                q.push(now * 2);
                checked[now * 2] = true;
                d[now * 2] = d[now] + 1;
            }
        }
    }
    printf("%d\n", d[k]);
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    checked[n] = true;
    d[n] = 0;
    q.push(n);
    bfs(n, k);
    return 0;
}

