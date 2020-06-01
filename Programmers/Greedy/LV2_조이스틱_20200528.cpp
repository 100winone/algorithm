#include <string>
#include <iostream>
using namespace std;
int solution(string name) {
    int answer = 0;
    int size = name.size();
    string checkName = "";
    for (int i = 0; i < size; ++i) {
        checkName += "A";
    }
    int cur = 0;
    while(name != checkName){
        int left = 0, right = 0, minIdx = 0, minCnt = size;
        for (int i = 0; i < size; ++i) {
            if(name[i] == checkName[i]) continue;
            if(cur > i){
                left = cur - i;
                right = size - cur + i;
            } else {
                left = cur + size - i;
                right = i - cur;
            }
            if(left < minCnt || right < minCnt){
                minCnt = min(left, right);
                minIdx = i;
            }
        }
        cur = minIdx;
        answer += minCnt;
        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        checkName[cur] = name[cur];
    }
    return answer;
}