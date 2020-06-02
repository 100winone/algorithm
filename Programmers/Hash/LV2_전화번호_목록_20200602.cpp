#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool cal(string shorter, string longer) {
    bool answer = true;
    int sSize = shorter.size();
    if (shorter == longer.substr(0, sSize)) {
        return false;
    }
    return answer;
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    int pSize = phone_book.size();
    vector<int> v;
    for (int i = 0; i < pSize - 1; ++i) {
        for (int j = i; j < pSize; ++j) {
            if(i == j) continue;
            if(phone_book[i].size() <= phone_book[j].size()) {
                answer = cal(phone_book[i], phone_book[j]);
                if(!answer) return answer;
            }
            else {
                answer = cal(phone_book[j], phone_book[i]);
                if(!answer) return answer;
            }
        }
    }
    return answer;
}