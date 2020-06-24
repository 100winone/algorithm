#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * 실패율 = 스테이지 도달했으나 클리어 하지 못한 플레이어 수 / 스테이지에 도달한 플레이어 수
 * 사용자가 현재 멈춰있는 스테이지 번호 배열 stages
 * 스테이지 갯수 N
 */

int failGrade[501];
int progress[501];
int cntTotalNum[501];

bool compare(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> tmpAnswer;
    for (int i = 0; i < stages.size(); ++i) {
        int num = stages[i];
        for (int j = 1; j <= num; ++j) {
            cntTotalNum[j]++;
        }
        failGrade[num]++;
    }
    for (int i = 1; i <= N; ++i) {
        if(cntTotalNum[i] == 0){
            tmpAnswer.push_back({0, i});
            continue;
        }
        double res = (double)failGrade[i] / cntTotalNum[i];
        tmpAnswer.push_back({res, i});
    }
    sort(tmpAnswer.begin(), tmpAnswer.end(), compare);
    for (int i = 0; i < tmpAnswer.size(); ++i) {
        answer.push_back(tmpAnswer[i].second);
    }
    return answer;
}
