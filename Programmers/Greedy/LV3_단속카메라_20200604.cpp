#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    for (int i = 0; i < routes.size();) {
        int left = routes[i][0];
        int right = routes[i][1];
        int idx = 0;
        for (int j = i; j < routes.size(); ++j) {
            if(left <= routes[j][0] && routes[j][0] <= right){
                left = routes[j][0];
                right = min(right, routes[j][1]);
                idx++;
            } else {
                break;
            }
        }
        answer++;
        i += idx;
    }
    return answer;
}