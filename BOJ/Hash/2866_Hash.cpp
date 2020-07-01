#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
string str[1002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    int cnt = 0;
    map <string, int> mpWord;

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        str[i];
    }
    int begin = 0;
    int end = r - 1;
    int mid = 0;
    bool finalFlag = false;

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
        if(!flag)
    }

    return 0;
}