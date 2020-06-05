#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i = 123; i <= 987; i++){
        int x = (i / 100); // 1
        int y = (i / 10) % 10; // 2
        int z = (i % 10); // 3 
        if((x == 0) || (y == 0) || (z == 0)) continue;
        if((x == y) || (y == z) || (x == z)) continue;
        for(int j = 0; j < baseball.size(); j++){
            
            int baseNum = baseball[j][0];
            int baseNumX = (baseNum / 100); 
            int baseNumY = (baseNum / 10) % 10;
            int baseNumZ = (baseNum % 10);
        
            int strike = 0;
            int ball = 0;
            
            if(x == baseNumX) strike++;
            if(y == baseNumY) strike++;
            if(z == baseNumZ) strike++;
            if(strike != baseball[j][1]) break;
            
            if(x == baseNumY || x == baseNumZ) ball++;
            if(y == baseNumX || y == baseNumZ) ball++;
            if(z == baseNumX || z == baseNumY) ball++;
            if(ball != baseball[j][2]) break;
            
            if(j == baseball.size() - 1) answer++;
        }
    }
    return answer;
}