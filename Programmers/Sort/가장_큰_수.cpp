#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    int numSize = numbers.size();
    for (int i = 0; i < numSize; ++i) {
        s.push_back(to_string(numbers[i]));
    }
    sort(s.begin(), s.end(), compare);
    for (int i = 0; i < numSize; ++i) {
        answer += s[i];
    }
    if(answer[0] == '0')  return "0";
    return answer;
}