/*7568 덩치 BruteForce 20200318*/
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> body;
    int a[n];
    fill_n(a, n, 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        body.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n;j++) {
            if(body[i].first > body[j].first){
                if(body[i].second > body[j].second){
                    a[j] += 1;
                }
                else continue;
            } else if(body[i].first < body[j].first){
                if(body[i].second < body[j].second){
                    a[i] += 1;
                } else continue;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}