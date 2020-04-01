/*11729 하노이 탑 이동 순서 Recursive 20200401*/
#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
using namespace std;
vector <pair<int, int>> v;

void hanoi(int n, int from, int by, int to){
    if(n == 1){
        v.push_back(make_pair(from, to));
    }
    else {
        hanoi(n - 1, from, to, by); // 1 3 2
        v.push_back(make_pair(from, to));
        hanoi(n - 1, by, from, to); // 2 1 3
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    hanoi(n, 1, 2 ,3);
    int sizeV = v.size();
    cout << sizeV << '\n';
    for (int i = 0; i < sizeV; ++i) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}