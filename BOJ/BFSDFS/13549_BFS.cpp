/*13549 숨바꼭질3 BFS 20200318*/
#include <stdio.h>
#include <queue>
#define MAX 200001
using namespace std;
bool checked[MAX];
int d[MAX];
queue<int> q;
queue<int> nextQ;
void bfs(){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now * 2 < MAX){ // n이 1이고 k가 2일때 때문에 곱하기가 먼저나와야함
            if(!checked[now * 2]){
                q.push(now * 2);
                checked[now * 2] = true;
                d[now * 2] = d[now];
            }
        }
        if(now - 1 >= 0){
            if(!checked[now - 1]){
                nextQ.push(now - 1);
                checked[now - 1] = true;
                d[now - 1] = d[now] + 1;
            }
        }
        if(now + 1 < MAX){
            if(!checked[now + 1]){
                nextQ.push(now + 1);
                checked[now + 1] = true;
                d[now + 1] = d[now] + 1;
            }
        }
        if(q.empty()){
            q = nextQ;
            nextQ = queue<int>();
        }
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    q.push(n);
    checked[n] = true;
    d[n] = 0;
    bfs();
    printf("%d\n", d[k]);
    return 0;
}

