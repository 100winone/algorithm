#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> ans;
    for (int i = 0; i < priorities.size(); ++i) {
        ans.push_back({priorities[i], i});
    }

    for (int i = 1; i < ans.size(); i++) {
        if (ans[0].first < ans[i].first) {
            queue<pair<int, int>> tmp;
            tmp.push({ans[0].first, ans[0].second});
            ans.pop_front();
            ans.push_back({tmp.front().first, tmp.front().second});
            tmp.pop();
            i = 0;
            continue;
        }
        if (i == ans.size() - 1) {
            answer++;
            i = 0;
            if (ans[0].second == location) {
                return answer;
            }
            ans.pop_front();
        }
    }
    answer++;
    return answer;
}