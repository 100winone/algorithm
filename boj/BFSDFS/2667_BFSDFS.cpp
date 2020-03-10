#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
string graph[26];
bool check[26][26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
int cnt;
vector<int> houseCnt;

void dfs(int x, int y){
    cnt++;
    check[x][y] = true;
    for(int i = 0; i < 4; i++){ // 네 방향체크
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX >= 0 && nextX < N && nextY >=0 && nextY < N){ // 범위 내에
            if(graph[nextX][nextY] == '1' && check[nextX][nextY] == false)
                dfs(nextX, nextY);
        }
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cin >> graph[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == '1' && check[i][j] == false){
                cnt = 0;
                dfs(i, j);
                houseCnt.push_back(cnt);
            }
        }
    }
    sort(houseCnt.begin(), houseCnt.end());
    printf("%d\n", houseCnt.size());
    for(int i = 0; i < houseCnt.size(); i++)
        printf("%d\n", houseCnt[i]);
    return 0;
}