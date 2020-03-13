/*6378 디지털 루트 , 문자열 20200313*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        string n;
        cin >> n;
        if(n == "0") break;
        int digit = 0;
        for (int i = 0; i < n.size(); ++i) {
            digit += n.at(i)-'0';
        }
        int temp = digit;
        digit = 0;
        while(temp){
            digit += (temp % 10);
            temp /= 10;
            if(temp == 0 && digit >= 10) {
                temp = digit;
                digit = 0;
            }
        }
        cout << digit << '\n';
    }
    return 0;
}