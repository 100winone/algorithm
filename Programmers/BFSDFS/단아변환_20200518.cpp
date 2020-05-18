#include <string>
#include <vector>
#include <iostream>
#define MAX 51
using namespace std;
int answer = 101;
int check[MAX];

bool isValidNum(string a, string b){
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) diff++;
    }
    if(diff == 1) return true;
    else return false;
}

void DFS(string begin, string target, vector<string> words, int cnt){
    for (int i = 0; i < words.size(); ++i) {
        if(isValidNum(begin, words[i])){
            if(target == words[i]){
                if(answer > cnt + 1){
                    answer = cnt + 1;
                    return;
                }
            }
            if(!check[i]){
                check[i] = true;
                DFS(words[i], target, words, cnt + 1);
                check[i] = false;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    for (int i = 0; i < words.size(); ++i) {
        if(target == words[i]) {
            flag = true;
            break;
        }
    }
    cout << flag << '\n';
    if(!flag) return 0;

    DFS(begin, target, words, 0);
    return answer;
}
