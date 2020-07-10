/* 2941 크로아티아 알파벳 20200710 문자열*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int res = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'c') {
            if (str[i + 1] == '=' || str[i + 1] == '-') {
                i++;
            }
        } else if (str[i] == 'z') {
            if (str[i + 1] == '=') {
                i++;
            }
        } else if (str[i] == 'd') {
            if (str[i + 1] == '-') {
                i++;
            } else if (str[i + 1] == 'z') {
                if (str[i + 2] == '=') {
                    i += 2;
                }
            }
        } else if (str[i] == 's') {
            if (str[i + 1] == '=') {
                i++;
            }
        } else if (str.substr(i, 2) == "lj" || str.substr(i, 2) == "nj") {
            i++;
        }
        res++;
    }
    cout << res << '\n';
    return 0;
}