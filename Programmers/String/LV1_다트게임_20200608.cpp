#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
 * 총 3번의 기회
 * 점수 0점에서 10점
 * S, D, T 점수 영역 존재하고 1제곱 2제곱 3제곱으로 계산
 * 옵션 - 스타상 "*" 해당점수와 바로전에 얻은점수 2배 곱 ,아차상 "#" 해당점수 마이너스
 * 스타상은 첫번째 경우에 나오면 첫번째만 2배
 * 스타상의 효과가 중쳡되면 점수 4배
 * "*" 과 "#"잉 중첩시 #의 점수 -2배
 * "*" "#"은 점수마다 둘 중 하나만 존재, 존재하지않을 수 있음
 *
 * */
int solution(string dartResult) {
    int answer = 0;
    int resSize = dartResult.size();
    string strNum = "";
    vector<int> numVec;
    for (int i = 0; i < resSize; ++i) {
        if(dartResult[i] != 'S' && dartResult[i] != 'D' && dartResult[i] != 'T'
        && dartResult[i] != '*' && dartResult[i] != '#'){
            strNum += dartResult[i];
        } else {
            int curNum = atoi(strNum.c_str());
            if(dartResult[i] == 'S'){
                numVec.push_back(curNum);  // numVec에 1드감
                strNum = "";
            } else if (dartResult[i] == 'D') {
                curNum = pow(curNum, 2);
                numVec.push_back(curNum);
                strNum = "";
            } else if (dartResult[i] == 'T'){
                curNum = pow(curNum, 3);
                numVec.push_back(curNum);
                strNum = "";
            } else if (dartResult[i] == '*'){
                if(numVec.size() > 1){ // 첫 번째 기회가 아니라 그 이상이면
                    numVec[numVec.size() - 1] *= 2;
                    numVec[numVec.size() - 2] *= 2;
                } else{
                    numVec[0] *= 2;
                }
            } else {
                numVec[numVec.size() - 1] *= -1;
            }
        }
    }
    for (int i = 0; i < numVec.size(); ++i) {
        answer += numVec[i];
    }
    return answer;
}