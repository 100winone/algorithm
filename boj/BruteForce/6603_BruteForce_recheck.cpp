/*6603 로또 BruteForce 20200310 다시체크*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        vector<int> d;
        for (int i = 0; i < n - 6; ++i) {
            d.push_back(0);
        }
        for (int i = 0; i < 6; ++i) {
            d.push_back(1);
        }
        vector<vector<int>> ans;
        do{
            vector<int> current;
            for (int i = 0; i < n; ++i) {
                if(d[i] == 1){
                    current.push_back(a[i]);
                }
            }
            ans.push_back(current);
        }
        while(next_permutation(d.begin(), d.end()));
        sort(ans.begin(), ans.end());
        for(auto &v : ans){ // auto 이중 vector쓸 때 유용.
            for (int i = 0; i < v.size(); ++i) {
                printf("%d ", v[i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}