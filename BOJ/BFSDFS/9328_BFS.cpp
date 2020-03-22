/*9328 열쇠 BFS recheck !!!! 20200322*/
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX 111
using namespace std;
char a[MAX][MAX];
bool visit[MAX][MAX];
bool key[26];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int H, W, answer;
string firstKey;

void bfs(){
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx <= H + 1 && ny >= 0 && ny <= W + 1){
                if(a[nx][ny] == '*' || visit[nx][ny] == true) continue;
                visit[nx][ny] = true;
                if(a[nx][ny] >= 'A' && a[nx][ny] <= 'Z'){
                    if(key[a[nx][ny] - 'A']){
                        q.push(make_pair(nx, ny));
                    } else{
                        door[a[nx][ny] - 'A'].push(make_pair(nx, ny));
                    }
                } else if (a[nx][ny] >= 'a' && a[nx][ny] <= 'z'){
                    q.push(make_pair(nx, ny));
                    if(!key[a[nx][ny] - 'a']){
                        key[a[nx][ny] - 'a'] = true;
                        while(!door[a[nx][ny] - 'a'].empty()){
                            q.push(door[a[nx][ny] - 'a'].front());
                            door[a[nx][ny] - 'a'].pop();
                        }
                    }
                } else{
                    q.push(make_pair(nx, ny));
                    if(a[nx][ny] == '$') answer++;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(visit, false, sizeof(visit));
        memset(key, false,sizeof(key));
        firstKey.clear();
        answer = 0;
        cin >> H >> W;
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> a[i][j];
            }
        }
        cin >> firstKey;
        for (int i = 0; i < firstKey.length(); ++i) {
            if(firstKey[i] == 0) continue;
            key[firstKey[i] - 'a'] = true; // Index에 넣기위해
        }

        bfs();
        cout << answer << '\n';
    }

    return 0;
}