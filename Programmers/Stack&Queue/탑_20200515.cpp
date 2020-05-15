#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> tmp;
    int n = heights.size();
    for (int i = n - 1; i >= 1; --i) {
        bool flag = false;
        for (int j = i - 1; j >= 0 ; --j) {
            if(heights[i] < heights[j]){
                tmp.push_back(j + 1);
                flag = true;
                break;
            }
        }
        if(!flag) tmp.push_back(0);
    }
    tmp.push_back(0);
    for (int i = n - 1; i >= 0 ; --i) {
        answer.push_back(tmp[i]);
    }
    return answer;
}