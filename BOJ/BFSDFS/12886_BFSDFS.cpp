/*12886 돌 그룹 BFS DFS 20200327*/
#include <stdio.h>
#define MAX 2001
using namespace std;

bool check[MAX][MAX];
int sum;
void recur(int x, int y){
    if(check[x][y]) return;
    check[x][y] = true;
    int firstArr[] = {x, y, sum - x - y};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(firstArr[i] < firstArr[j]){
                int secondArr[] = {x, y, sum - x - y};
                secondArr[i] += firstArr[i];
                secondArr[j] -= firstArr[i];
                recur(secondArr[0], secondArr[1]);
            }
        }

    }
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;
    if(sum % 3 != 0){
        printf("0\n");
        return 0;
    }
    recur(a, b);
    int res = sum / 3;
    if(check[res][res]){
        printf("1\n");
    } else{
        printf("0\n");
    }
    return 0;
}