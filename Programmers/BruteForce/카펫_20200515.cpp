#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로가 세로보다 김
    int total = brown + yellow; // 12
    int limit = (int)sqrt(total);
    for (int row = 3; row <= limit; ++row) {
        if(total % row == 0){
            int tmp = total / row;
            if(yellow == (tmp - 2) * (row - 2)){
                answer.push_back(tmp);
                answer.push_back(row);
                return answer;
            }
        }
    }
}