#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> citations){
    int answer = 0;
    int n = citations.size(); // 5개
    sort(citations.begin(), citations.end());

    int nMax = citations[n - 1]; // 최대값
    for (int i = 0; i <= nMax; ++i) {
        int tmp = 0;
        for (int j = 0; j < n; ++j) {
            if(citations[j] >= i) tmp++;
        }
        if(tmp >= i) answer = max(answer, i);
    }
    return answer;
}