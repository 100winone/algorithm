/*16928 BFS  20200403*/
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#define MAX 101
using namespace std;
int dist[MAX];
int nextT[MAX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 100 ; ++i) {
    nextT[i] = i;
    dist[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nextT[x] = y;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        nextT[x] = y;
    }
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6 ; ++i) {
            int y = x + i;
            if(y > 100) continue;
            y = nextT[y];
            if(dist[y] == -1){
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}