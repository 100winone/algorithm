/*1062 가르침 BruteForce DFS */
#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;
string str[MAX];
bool alpha[26];
int n, k;
int res;
int countWord(){
    int cnt = 0;
    bool isRead = false;
    for (int i = 0; i < n; ++i) {
        isRead = true;
        string s = str[i];
        for (int j = 0; j < s.length(); ++j) {
            if(alpha[s[j] - 'a'] == false){
                isRead = false;
                break;
            }
        }
        if(isRead){
            cnt++;
        }
    }
    return cnt;
}
void DFS(int idx, int cnt){
    if(cnt == k){
        int cntWord = countWord();
        res = max(cntWord, res);
        return;
    }
    for (int i = idx; i < 26; ++i) {
        if(alpha[i]) continue;
        alpha[i] = true;
        DFS(i, cnt + 1);
        alpha[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    if(k < 5){
        cout << 0 << '\n';
        return 0;
    }
    alpha['a' - 'a'] = true;
    alpha['c' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    k -= 5;
    DFS(0, 0);
    cout << res << '\n';
    return 0;
}