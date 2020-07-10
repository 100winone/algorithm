/* 10994 별 찍기 - 19 DFS 20200710 */
#include <iostream>
#define MAX 401
using namespace std;

char graph[MAX][MAX];
void makeStar(int curNum, int x, int y){
    if(curNum == 1){
        graph[x][y] = '*';
        return;
    }
    int regNum = (4 * (curNum - 1)) + 1;
    for (int i = 0; i < regNum; ++i) {
        if((i == 0) || (i == regNum - 1)){
            for (int j = 0; j < regNum; ++j) {
                graph[x + i][y + j] = '*';
            }
            continue;
        }
        graph[x + i][y] = '*';
        graph[x + i][y + regNum - 1] = '*';
    }
    makeStar(curNum - 1, x + 2, y + 2);
}
int main(){
    int N;
    cin >> N;

    makeStar(N, 0, 0); // 좌상단좌표표

   int regNum = (4 * (N - 1)) + 1;
    for (int i = 0; i < regNum; ++i) {
        for (int j = 0; j < regNum; ++j) {
            if(graph[i][j] == '*') cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}