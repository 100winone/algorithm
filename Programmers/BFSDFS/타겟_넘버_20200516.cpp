#include <iostream>
#include <vector>
using namespace std;
int answer;


void DFS(vector<int> numbers, int target, int cnt, int sum){
    if(cnt == numbers.size()){
        if(sum == target)
            answer++;
        return;
    }
    DFS(numbers, target, cnt + 1, sum + numbers[cnt]);
    DFS(numbers, target, cnt + 1, sum - numbers[cnt]);
}
int solution(vector<int> numbers, int target) {

    DFS(numbers, target, 0, 0);
    return answer;
}
