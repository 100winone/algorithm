#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
/*
 * 닉네임 변경방법 
 * 1. 새로운 닉네임으로 다시 들어가기
 * 2. 채팅 방에서 닉네임 바꾸기
 * 
 * 닉네임 바꾸면 기존 메시지의 닉네임도 전부 변경
 * 닉네임 변경을 기록이 담긴 문자열 배열 record가 배열로 주어짐
 * 최종적으로 방을 개설한 사람이 보게된느 메시지 출력
 * 
 * Enter, Leave, Change중 하나*/
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> v;
    map<string, string> mp;
    for (int i = 0; i < record.size(); ++i) {
        if (record[i].substr(0, 1) == "E") {
            string id = "";
            int j;
            for (j = 6; record[i][j] != ' '; ++j) {
                id += record[i][j];
            }
            mp[id] = record[i].substr(j + 1);
            v.push_back({id, "E"});
        } else if (record[i].substr(0, 1) == "L") {
            string id = "";
            id = record[i].substr(6);
            v.push_back({id, "L"});
        } else {
            string id = "";
            int j;
            for (j = 7; record[i][j] != ' '; ++j) {
                id += record[i][j];
            }
            mp[id] = record[i].substr(j + 1);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        string res = "";
        res += mp[v[i].first];
        if(v[i].second == "E") res += "님이 들어왔습니다.";
        else res += "님이 나갔습니다.";

        answer.push_back(res);
    }
    return answer;
}
