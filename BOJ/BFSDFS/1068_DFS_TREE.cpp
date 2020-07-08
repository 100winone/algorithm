/* 트리 DFS 20200708 */
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;
bool flag[MAX];
int tree[MAX];
int n;
void removeNode(int target){
    flag[target] = false;
    for (int i = 0; i < n; ++i) {
        if(tree[i] == target){
            removeNode(i);
            flag[i] = false;
        }
    }
}
int main(){
    memset(flag, true, sizeof(flag));
    int nodeCount[MAX] = {0, };
    int target;
    int res = 0;
    int rootNum;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
        flag[i] = true;
        if(tree[i] == -1) rootNum = tree[i];
    }
    cin >> target;
    removeNode(target);

    for (int i = 0; i < n; ++i) {
        if(i == rootNum) continue;
        if(tree[i] == -1) nodeCount[i]++;
        if(flag[i]) nodeCount[tree[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if(flag[i] && (nodeCount[i] == 0)) {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}