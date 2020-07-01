#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
string str[1002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    map <string, int> mpWord;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> str[i];
    }
    int begin = 0;
    int end = r - 1;
    int mid = 0;
    bool finalFlag;

    while(begin <= end){
        bool flag = true;
        mid = (begin + end) / 2;
        for (int i = 0; i < c; ++i) {
            string tmp = "";
            for (int j = mid; j < r; ++j) {
                tmp += str[j][i];
            }
            if(mpWord[tmp]){
                flag = false;
                break;
            }
            mpWord[tmp]++;
        }
        if(!flag) end = mid - 1;// 중복되는애가 있으면
        else begin = mid + 1;
        finalFlag = flag; // 마지막 애가 겹치는애가 있으면 mid - 1 else mid
        mpWord.clear();
    }
    if(!finalFlag) cout << mid - 1 << '\n';
    else cout << mid << '\n';

    return 0;
}