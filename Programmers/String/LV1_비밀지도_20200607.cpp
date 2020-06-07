#include <string>
#include <vector>
#include <iostream>
using namespace std;
pair<string, string> toBinary(int a, int b, int n){
    string resA = "";
    string resB = "";
    for (int i = 1; a > 0; i *= 10) {
        resA = to_string(a % 2) + resA;
        a /= 2;
    }
    for (int i = 1; b > 0; i *= 10) {
        resB = to_string(b % 2) + resB;
        b /= 2;
    }
    int aSize = resA.size();
    int bSize = resB.size();
    if(aSize < n){
        string tmp = "";
        for (int i = 0; i < n - aSize; ++i) {
            tmp += "0";
        }
        resA = tmp + resA;
    }
    if(bSize < n){
        string tmp = "";
        for (int i = 0; i < n - bSize; ++i) {
            tmp += "0";
        }
        resB = tmp + resB;
    }
    return {resA, resB};
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        pair<string, string> tmp;
        tmp = toBinary(arr1[i], arr2[i], n);
//        cout << tmp.first << ' ' << tmp.second << '\n' ;
        string str = "";
        for (int j = 0; j < n; ++j) {
            if(tmp.first[j] == '1' || tmp.second[j] == '1') str += "#";
            else str += " ";
        }
        answer.push_back(str);
    }
    return answer;
}

int main(){
    vector<string> a = solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28});
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}