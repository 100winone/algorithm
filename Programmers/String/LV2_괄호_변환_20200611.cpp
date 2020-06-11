#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 * ( ) 갯수 같으면 균형잡힌 괄호 문자열
 * ( ) 괄호의 짝도 모주 맞으면 올바른 괄호 문자열
 * 1. 입력 비어있으면 빈 문자열 반환
 * 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분할, 단 u는 더 이상 균형잡힌 문자열ㄹ ㅗ분리 못하고 v는 빈 문자열 가능
 * 3. 문자열 u가 올바른 괄호 문자열이라면 문자열 v에 대해 1단계 부터 다시 수행
 *   3-1 수행한 결과 문자열을 u에 이어 붙인 후 반환
 * 4. 문자열 u가 올바른 괄호 문자열이아니라면 ?
 *   4-1 빈 문자열에 첫 번째 문자로 ( 붙임
 *   4-2 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어붙임
 *   4-3 )를 다시 붙임
 *   4-4 u의 첫 번째와 마지막을 제거하고 나머지 문자열의 괄호 방향을 뒤집어 뒤에 붙임
 *   4-5 생성된 문자열 반환
 * */
bool isValidString(string u){
    int check = 0;
    for (int i = 0; i < u.length(); ++i) {
        if(u[i] == '(') check++;
        else check--;

        if(check < 0) return false;
    }
    return true;
}

string solution(string p) {
    if(p.size() == 0)
        return "";

    string answer = "";
    string u, v;
    int frontS, lastS;
    frontS = lastS = 0;

    for (int i = 0; i < p.size(); ++i) {
        if(p[i] =='(') frontS++;
        else lastS++;
        if(frontS == lastS){
            u = p.substr(0, frontS + lastS);
            v = p.substr(frontS + lastS);
            break;
        }
    }

    if(isValidString(u) == true){
        answer = answer + u;
        answer = answer + solution(v);
        return answer;
    } else {
        string tmp = "(";
        tmp = tmp + solution(v);
        tmp = tmp + ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); ++i) {
            if(u[i] == '(') tmp = tmp + ")";
            else tmp = tmp + "(";
        }
        return tmp;
    }
}