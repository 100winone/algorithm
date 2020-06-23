#include <iostream>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int price[4];
        int month[13];
        int totalPrice = -987654321;
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            cin >> price[i];
        }
        for (int j = 0; j < 12; ++j) {
            cin >> month[j];
        }
        int dayMonth = price[1] / price[0] + 1;


    }
    return 0;
}