/* 1316 그룹단어체크 실버 5 20200707*/
#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string words[MAX];
int main(){

    int n;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        cin >> words[i];
        int check[26] = {0, };
        for (int j = 0; j < words[i].size(); ++j) {
            int index = words[i][j] - 'a';
            check[index]++;
        }
        int straight = 1;
        for (int j = 0; j < words[i].size() - 1; ++j) {
            if(words[i][j] != words[i][j + 1]){
                int index = words[i][j] - 'a';
                if(check[index] != straight){
                    flag = false;
                    break;
                }
                straight = 1;
                continue;
            }
            straight++;
        }
        if(flag) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}