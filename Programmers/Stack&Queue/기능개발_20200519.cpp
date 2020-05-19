#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> index;
    for (int i = 0; i < progresses.size(); ++i) {
        int days = 0;
        while(true){
            days += 1;
            int cal = progresses[i] + (speeds[i] * days);
            if(cal >= 100) {
                index.push_back(days);
                break;
            }
        }
    }
    int cnt = 0;
    int tmp = index[0];
    for (int i = 0; i < progresses.size(); ++i) {
        if(tmp < index[i]){
            answer.push_back(cnt);
            cnt = 1;
            tmp = index[i];
        } else {
            cnt++;
        }
        if(i == progresses.size() - 1){
            answer.push_back(cnt);
        }
    }
    return answer;
}