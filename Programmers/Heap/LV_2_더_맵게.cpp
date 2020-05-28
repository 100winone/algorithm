#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int lessSpicy;
    int secondLessSpicy;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); // 오름차순

    while(pq.top() < K){
        if(pq.size() == 1) return -1; // 더 이상 섞을 음식이 없으면 -1

        lessSpicy = pq.top();
        pq.pop();

        secondLessSpicy = pq.top();
        pq.pop();

        int tmp;
        tmp = lessSpicy + (secondLessSpicy * 2);
        pq.push(tmp);
        answer++;
    }
    return answer;
}