#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue <int> q;
    for (int i = 0; i < truck_weights.size(); i++) {
        while(true){
            if(q.empty()){
                q.push(truck_weights[i]);
                sum += truck_weights[i];
                answer++;
                break;
            } else if(q.size() == bridge_length){
                sum -= q.front();
                q.pop();
            } else{
                if(sum + truck_weights[i] > weight){
                    q.push(0);
                    answer++;
                } else {
                    q.push(truck_weights[i]);
                    sum += truck_weights[i];
                    answer++;
                    break;
                }
            }
        }
    }
    answer += bridge_length; // 길이만큼 더해줘야함
    return answer;
}