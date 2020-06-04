#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int left = 0;
    int right = people.size() - 1;

    while(left < right + 1){
        if(people[left] + people[right] <= limit ){
            right--;
        }
        left++;
        answer++;
    }
    return answer;
}