/* 팰린드롬*/
#include <iostream>
#define MAX 100

using namespace std;
char graph[MAX][MAX];
bool isPalindrome(int x, int y, int len){
    for (int i = 0; i < (len + 1) / 2; ++i) {
        if(graph[x][y + i] != graph[x][y + len -i  -1]) return false;
    }
    return true;
}
int getPalindrome(){
    int max = 0;
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            for (int k = MAX - j; k > max; --k) {
                if(isPalindrome(i, j, k)){
                    if(max < k) max = k;
                    break;
                }
            }
        }
    }
    return max;
}
int main() {
    int ans = 0;

    for (int tc = 1; tc <= 10; ++tc) {
        int n;
        cin >> n;
        for (int i = 0; i < MAX; ++i) {
            cin >> graph[i];
        }
        
        ans = getPalindrome();

        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                if(i < j){
                    char tmp = graph[i][j];
                    graph[i][j] = graph[j][i];
                    graph[j][i] = tmp;
                }
            }
        }
        ans = getPalindrome() < ans ? ans : getPalindrome();
        cout << '#' << tc << ' ' << ans << '\n';
        ans = 0;
    }
    return 0;
}