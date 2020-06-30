#include <iostream>
#define MAX 501
using namespace std;

int N, M;
int graph[MAX][MAX];
int maxSum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
        }
    }
    return 0;
}