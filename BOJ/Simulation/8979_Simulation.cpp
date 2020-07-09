/*8979 올림픽 Simulation 20200709*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Medal{
    int gold;
    int silver;
    int bronze;
};
int N, K;
bool compare(pair<int, Medal> v1, pair<int, Medal> v2){
    if(v1.second.gold == v2.second.gold){
        if(v1.second.silver == v2.second.silver){
            if(v1.second.bronze == v2.second.bronze){
                if(v1.first == K){
                    return K;
                } else if (v2.first == K){
                    return K;
                }
            }
            return v1.second.bronze > v2.second.bronze;
        }
        return v1.second.silver > v2.second.silver;
    }
    return v1.second.gold > v2.second.gold;
}
int main() {

    int rank;
    Medal medal;
    vector<pair<int, Medal>> nation;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        nation.push_back({a, {b, c, d}});
    }
    sort(nation.begin(), nation.end(), compare);
    for (int i = 0; i < N; ++i) {
        if(nation[i].first == K) {
            rank = i + 1;
            break;
        }
    }
    cout << rank << '\n';
    return 0;
}
