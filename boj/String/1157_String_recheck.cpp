/*1157 문자열 다시한번 되새기기 recheck 20200311*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int alpha[26];
int main(){
    string s;
    cin >> s;
    char result;
    for (int i = 0; i < s.length(); ++i) {
        if('A' <= s[i] && s[i] <= 'Z'){
            alpha[s[i] - 'A']++;
            if(i == 0)
                result = s[i];
            else
                if (alpha[s[i] - 'A'] > alpha[result - 'A'])
                    result = s[i];

        }
        else if ('a' <= s[i] && 'z' >= s[i]){
            alpha[s[i] - 'a']++;
            if(i == 0) {
                result = s[i] -'a' + 'A';
            } else
                if (alpha[s[i] - 'a'] > alpha[result - 'A'])
                    result = s[i] - 'a' + 'A';
        }
    }
    for (int i = 0; i < 26; ++i) {
        if((i + 'A') != result && alpha[i] == alpha[result - 'A']){
            printf("?\n");
            return 0;
        }
    }
    printf("%c\n", result);
    return 0;
}
