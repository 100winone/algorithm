/*1764 듣보잡 Simulation 20200327*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <string> a;
    vector <string> s;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x + y; ++i) {
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < x + y - 1; ++i) {
        if(a[i].compare(a[i + 1]) == 0){
            s.push_back(a[i]);
            i++;
        }
    }
    cout << s.size() << '\n';
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << '\n';
    }
    return 0;
}