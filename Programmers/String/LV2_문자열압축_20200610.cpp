#include <string>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();

    if(s.length() == 1)
        return 1;

    for(int i = 1; i <= s.length() / 2; i++) { //비교 갯수 지정
        int cnt = 0;
        string initStr = s.substr(0, i);
        string tmp, cp;
        for (int j = i; j < s.length(); j += i) {
            tmp = s.substr(j, i);
            if(initStr == tmp){
                cnt++;
            } else {
                if(cnt == 0){
                    cp += initStr;
                    initStr = tmp;
                } else {
                    cp = cp + to_string(cnt + 1) + initStr;
                    initStr = tmp;
                    cnt = 0;
                }
            }
            if(j + i >= s.length()){
                if(cnt != 0){
                    cp = cp + to_string(cnt + 1) + initStr;
                } else {
                    cp = cp + s.substr(j);
                }
            }
        }
        int sizeCp = cp.size();
        answer = min(answer, sizeCp);
    }
    return answer;
}
