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
        if(!flag[i]) continue;
        if(tree[i] == target){
            removeNode(i);
        }
    }
}
int main(){
    memset(flag, true, sizeof(flag));
    int nodeCount[MAX] = {0, };
    int target;
    int res = 0;
    int rootNum;
    bool rootFlag = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
        flag[i] = true;
        if(tree[i] == -1) rootNum = i;
    }
    cin >> target;
    removeNode(target);

    for (int i = 0; i < n; ++i) {
        if(i == rootNum) continue;
        if(tree[i] == rootNum) rootFlag = false;
        if(flag[i]) nodeCount[tree[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if(flag[i] && (nodeCount[i] == 0)) {
            if(i == rootNum && rootFlag) {
                res++;
                continue;
            }
            res++;
        }
    }

    cout << res << '\n';
    return 0;
}