/*16637 괄호추가하기 BruteForce DFS 20200422
 * 생각해내는게 좀 어려움
 * 골드 3
 * */
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 20
using namespace std;

int num[MAX];
int op[MAX];
int n;
int opCnt; // 연산자 갯수
int ans = -2147000000;

int cal(int a, int b, char ch){
    if(ch == '+') return a + b;
    else if(ch == '*') return a * b;
    else return a - b;
}

void DFS(int index, int res){
    if(index >= opCnt){
        ans = max(ans, res);
        return;
    }
    int curRes = cal(res, num[index + 1], op[index]);
    DFS(index + 1, curRes);
    if(index + 1 < opCnt){
        int afterRes = cal(num[index + 1], num[index + 2], op[index + 1]); // 위에서 먼저해주고
        int curRes = cal(res, afterRes, op[index]); // 아래거로
        DFS(index + 2, curRes);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> n;
    cin >> str;
    int idx = 0;
    int opIdx = 0;

    int strSize = str.size();
    for (int i = 0; i < strSize; ++i) {
        if(i % 2 == 0) {
            num[idx] = str[i] - '0';
            idx += 1;
        } else {
            op[opIdx] = str[i];
            opIdx += 1;
        }
    }
    opCnt = n / 2;

    if(n == 1){
        cout << num[0] << '\n';
        return 0;
    } else if(n == 3){
        cout << cal(num[0], num[1], op[0]) << '\n';
        return 0;
    }
    DFS(0, num[0]);
    cout << ans << '\n';
    return 0;
}