#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    vector<pair<string, int>> v;
    for (int i = 0; i < genres.size(); ++i) {
        mp[genres[i]] += plays[i];
    }
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end() ; ++it) {
        v.push_back({it->first, it->second});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); ++i) {
        int n1 = 0; // 첫 인덱스
        int n2 = 0; // 두 번째 인덱스
        int a1 = 0; // 값 첫번째로 큰애
        int a2 = 0; // 두 번째로 큰애
        int tmp;
        for (int j = 0; j < genres.size(); ++j) {
            if(v[i].first == genres[j]){
                if(a1 < plays[j]){
                    a2 = a1;
                    a1 = plays[j];
                    n2 = n1;
                    n1 = j;
                } else {
                    if(a2 < plays[j]){
                        a2 = plays[j];
                        n2 = j;
                    }
                }
            }
        }
        if(a2 == 0) answer.push_back(n1);
        else {
            answer.push_back(n1);
            answer.push_back(n2);
        }
    }
    return answer;
}