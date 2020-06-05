#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int check = 0; //'(' 면 ++ ')' --로
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
             check++;
         else 
             check--;
        if(check < 0) {
            answer = false;
            break;
        }
    }
    if(check != 0) answer = false;
    return answer;
}