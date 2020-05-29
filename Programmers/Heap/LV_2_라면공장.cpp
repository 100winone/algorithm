#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int day = 0;
    int idx = 0;
    priority_queue<int, vector<int>, less<int>> pq; // 오름차순
    while(day < k){
        if(dates[idx] <= day){
            pq.push(supplies[idx]);
            idx += 1;
        }
        if(stock == 0){
            answer++;
            stock += pq.top();
            pq.pop();
        }
        stock--;
        day++;
    }
    return answer;
}