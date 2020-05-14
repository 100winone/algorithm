#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool select[10];
bool checkNum[10000000];
int answer = 0;

bool validation(int num){
    if(num == 1 || num == 0) return false;
    for (int i = 2; i < sqrt(num); ++i) {
        if(num % i == 0) return false;
    }
    return true;
}
void DFS(int cnt, string numbers, string str){
    if(str != "" && checkNum[stoi(str)] == false){
        int tmp = stoi(str);
        checkNum[tmp] = true;
        if(validation(tmp)) answer++;
    }
    for (int i = 0; i < numbers.size(); ++i) {
        if(select[i] == true) continue;
        select[i] = true;
        DFS(cnt + 1, numbers, str + numbers[i]);
        select[i] = false;
    }
}
int solution(string numbers) {
    int answer = 0;
    DFS(0, numbers, "");
    return answer;
}