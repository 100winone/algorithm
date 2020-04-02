/*2151 BFS 어려윰 20200402*/
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> b(n, vector<int>(n));
    vector<pair<int, int>> v;
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            if(s[i][j] == '#'){
                if(start == -1){
                    start = v.size();
                } else{
                    end = v.size();
                }
                v.push_back(make_pair(i, j));
                b[i][j] = v.size() - 1; // 몇 번 정점인지
            } else if(s[i][j] == '!'){
                v.push_back(make_pair(i, j));
                b[i][j] = v.size() - 1;
            }
        }
    }
    int m = v.size(); // 간선 찾기 과정
    vector<vector<bool>> a(m, vector<bool>(m, false)); // a 벡터
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int x = v[i].first + dx[j];
            int y = v[i].second + dy[j];
            while(0 <= x && x < n && 0 <= y && y < n){
                if(s[x][y] == '*') break;
                if(s[x][y] == '!' || s[x][y] == '#'){
                    a[i][b[x][y]] = true;
                }
                x += dx[j];
                y += dy[j];
            }
        }
    }
    queue<int> q;
    vector<int> dist(m, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < m; ++i) {
            if(a[now][i] && dist[i] == -1){
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }
    cout << dist[end] - 1 << '\n';
    return 0;
}