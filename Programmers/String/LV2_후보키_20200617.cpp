#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
/*
 * 후보키 : 유일성 - 릴레이션에 있는 모든 튜플에 대해 유일하게 식별
 *         최소성 - 유일성을 가진 키를 구성하는 속성 중 하나라도 제외하는 경우 유일성이 깨짐
 *
 * */
using namespace std;
int col;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    vector<int> candidates; // 유일성 만족하는 아이들 입력

    for (int i = 1; i < 1 << col; ++i) {

    }
    return answer;
}