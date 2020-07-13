/* 15651 N과 M (3) 20200713 */
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> v;
void DFS(int cnt){
    if(cnt == M){
        for (int i = 1; i <= M; ++i) {
            cout << v[i - 1] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        v.push_back(i);
        DFS(cnt + 1);
        v.pop_back();
    }
}
int main(){
    cin >> N >> M;
    DFS(0);
    return 0;
}


