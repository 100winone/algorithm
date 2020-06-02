#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int numLen = number.length() - k;
    vector<int> v;
    for (int i = numLen; i > 0; --i) {
        int idx, maxNum = 0;
        for (int j = 0; j < number.size() - i + 1; ++j) {
            if(maxNum < number[j]){
                maxNum = number[j];
                idx = j;
            }
        }
        number.replace(0, idx + 1, " ");
        v.push_back(maxNum);
    }
    for (int i = 0; i < numLen; ++i) {
        answer += v[i];
    }
    return answer;
}