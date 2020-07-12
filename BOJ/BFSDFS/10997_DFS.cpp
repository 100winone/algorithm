/* 10997 별 찍기 22 DFS 20200712 Difficult*/
#include <iostream>
#define MAX 500
using namespace std;
int N;
char starGraph[MAX][MAX];

void DFS(int x, int y, int depth){
    if(depth == 2){
        for (int i = 0; i < 5; ++i) {
            starGraph[x][y + i] = '*';
            starGraph[x + 6][y + i] = '*';
        }

        for (int i = 1; i < 6; ++i) {
            starGraph[x + i][y] = '*';
        }
        for (int i = 2; i < 6; ++i) {
            starGraph[x + i][y + 4] = '*';
            if(i > 4) continue;
            starGraph[x + i][y + 2] = '*';
        }
        starGraph[x + 2][y + 3] = '*';
        return;
    }
    // 맨 위 아래
    for (int i = 0; i < 4 * (depth - 1) + 1; ++i) {
        starGraph[x][y + i] = '*';
        starGraph[x + 4 * depth - 1 - 1][y + i] = '*';
    }
    for (int i = 1; i < 4 * depth - 1; ++i) {
        starGraph[x + i][y] = '*';
        if(i == 1) continue;
        starGraph[x + i][y + 4 * (depth - 1)] = '*';
    }
    starGraph[x + 2][y + 4 * (depth - 1) - 1] = '*';

    DFS(x + 2, y + 2, depth - 1);
    return;
}
int main() {

    cin >> N;
    if(N == 1){
        cout << '*' << '\n';
        return 0;
    }
    DFS(0, 0, N);
    for (int i = 0; i < 4 * N - 1; ++i) {
        if(i == 1){
            cout << '*' << '\n';
            continue;
        }
        for (int j = 0; j < 4 * (N - 1) + 1; ++j) {
            char star = starGraph[i][j] == '*' ? '*' : ' ';
            cout << star;
        }
        cout << '\n';
    }
    return 0;
}