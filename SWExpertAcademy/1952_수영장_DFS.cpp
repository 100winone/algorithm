#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int price[4] = {0, };
        int month[13] = {0, }; // 사용하는 날짜 갯수
        int diffMonthAndDay[13] = {0, }; // 일로써 할 것인지 달로써 할 것인지
        int answer[13] = {0, };
        for (int j = 0; j < 4; ++j) {
            cin >> price[j];
        }
        for (int j = 1; j <= 12; ++j) {
            cin >> month[j];
        }
        for (int j = 1; j <= 12; ++j) {
            diffMonthAndDay[j] = min((price[0] * month[j]), price[1]);
        }
        for (int j = 1; j <= 12; ++j) {
            answer[j] = answer[j - 1] + diffMonthAndDay[j];
            if(j >= 3) {
                if(answer[j] > answer[j - 3] + price[2]){
                    answer[j] = answer[j - 3] + price[2];
                }
            }
        }
        /* answer[12]랑 1년 값이랑 비교 */
        if(answer[12] > price[3]) answer[12] = price[3];
        cout << '#' << i << ' ' << answer[12] << '\n';
    }

    return 0;
}
