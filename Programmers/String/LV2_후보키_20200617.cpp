#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
/*
 * 후보키 : 유일성 - 릴레이션에 있는 모든 튜플에 대해 유일하게 식별
 *         최소성 - 유일성을 가진 키를 구성하는 속성 중 하나라도 제외하는 경우 유일성이 깨짐
 *
 * */
using namespace std;

int countBits(int num){
    int cnt = 0;
    while(num){
        if(num & 1) cnt++;
        num >> 1;
    }
    return cnt;
}
bool compare(int a, int b){
    int x = countBits(a); // 비트 갯수 세기
    int y = countBits(b);
    return x > y; // 1로 켜진거 큰게 앞으로
}
bool check(vector<vector<string>> relation, int row, int col, int subset){
    for (int i = 0; i < row - 1; ++i) {
        for (int j = i + 1; j < row; ++j) {
            bool flag = true;
            for (int k = 0; k < col; ++k) {
                if((subset & 1 << k) == 0) continue; // k의 속성 사용되고있다는 이야기
                if(relation[i][k] != relation[j][k]){
                    flag = false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    vector<int> candidates; // 유일성 만족하는 아이들 입력

    for (int i = 1; i < 1 << col; ++i) {
        if(check(relation, row, col, i)) candidates.push_back(i);
    }


    sort(candidates.begin(), candidates.end(), compare); // 원소 갯수 많은애들 기준으로 정렬되어있음
    while(!candidates.empty()){ // candidates 는 유효성을 만족한 아이들
        int n = candidates.back(); // 마지막에 있는 애를 빼내기 , 가장 적은 속성으로 이루어진 아이 , 후보키가 될 수 있음
        candidates.pop_back(); // 지우기
        answer++;
        for (vector<int>::iterator it = candidates.begin(); it != candidates.end();) { // iterator 사용법 알기
            if((n & *it) == n){ // 모든 비트가 동일하게 켜졌다 모두 이 비트를 포함하고 있다니까 최소성을 만족시키지 못함
                it = candidates.erase(it);
            } else {
                ++it;
            }
        }
    }
    return answer;
}