#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size() - 1; ++i) {
        int sec = 0;
        bool flag = false;
        for (int j = i + 1; j < prices.size(); ++j) {
            if(prices[i] > prices[j]){
                flag = true;
                sec++;
                answer.push_back(sec);
                break;
            }
            sec++;
        }
        if(flag) continue;
        answer.push_back(sec);
    }
    answer.push_back(0);
    return answer;
}