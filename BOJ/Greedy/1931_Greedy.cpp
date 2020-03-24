/*1931 Greedy 회의실배정 20200324*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.push_back(make_pair(y, x));
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int endTime = a[0].first;
    for (int i = 1; i < n; ++i) {
        if(endTime <= a[i].second){
            endTime = a[i].first;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}