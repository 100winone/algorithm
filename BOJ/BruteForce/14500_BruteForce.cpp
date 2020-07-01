#include <iostream>
#define MAX 501
using namespace std;

int N, M;
int graph[MAX][MAX];
int tetro[19][3][2] = {
        {{0,1}, {0,2}, {0,3}},
        {{1,0}, {2,0}, {3,0}},
        {{1,0}, {1,1}, {1,2}},
        {{0,1}, {1,0}, {2,0}},
        {{0,1}, {0,2}, {1,2}},
        {{1,0}, {2,0}, {2,-1}},
        {{0,1}, {0,2}, {-1,2}},
        {{1,0}, {2,0}, {2,1}},
        {{0,1}, {0,2}, {1,0}},
        {{0,1}, {1,1}, {2,1}},
        {{0,1}, {1,0}, {1,1}},
        {{0,1}, {-1,1}, {-1,2}},
        {{1,0}, {1,1}, {2,1}},
        {{0,1}, {1,1}, {1,2}},
        {{1,0}, {1,-1}, {2,-1}},
        {{0,1}, {0,2}, {-1,1}},
        {{0,1}, {0,2}, {1,1}},
        {{1,0}, {2,0}, {1,1}},
        {{1,0}, {2,0}, {1,-1}}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int maxSum = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];
        }
    }
    for (int k = 0; k < 19; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int sum = graph[i][j];
                bool flag = true;
                for (int l = 0; l < 3; ++l) {
                    int x = i + tetro[k][l][0];
                    int y = j + tetro[k][l][1];
                    if(x >= 0 && x < N && y >= 0 && y < M){
                        sum += graph[x][y];
                    } else {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    if(sum > maxSum) maxSum = sum;
            }
        }
    }
    cout << maxSum << '\n';
    return 0;
}