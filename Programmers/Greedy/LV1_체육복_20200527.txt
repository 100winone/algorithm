#include <vector>
#include <iostream>
using namespace std;
bool check[31];
bool isChanged[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    for (int i = 0; i < reserve.size(); ++i) {
        check[reserve[i]] = true;
    }
    for (int i = 0; i < lost.size(); ++i) {
        for (int j = 0; j < reserve.size(); ++j) {
            if(lost[i] == reserve[j]){
                isChanged[reserve[j]] = true;
                check[reserve[j]] = false;
                answer++;
                continue;
            }
        }
    }

    for (int i = 0; i < lost.size(); ++i) {

        int tmp = lost[i]; // 2
        if(isChanged[tmp]) continue;
        if(check[tmp - 1]) {
            answer++;
            check[tmp - 1] = false;
            continue;
        } else if(check[tmp + 1]){
            answer++;
            check[tmp + 1] = false;
            continue;
        }
    }
    return answer;
}