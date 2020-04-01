/*14395 4연산 BFS 20200401*/
#include <iostream>
#include <set>
#include <cstring>
#include <tuple>
#include <string>
#include <queue>
using namespace std;
long long limit = 1000000000LL;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long s, t;
    cin >> s >> t;

    if(s == t) {
        cout << '0' << '\n';
        return 0;
    }
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push(make_pair(s, ""));
    check.insert(s);
    while(!q.empty()){
        long long x;
        string str;
        tie(x, str) = q.front();
        q.pop();
        if(x == t) {
            cout << str << '\n';
            return 0;
        }
        if(0 <= x * x && x * x <= limit && check.count(x * x) == 0){
            q.push(make_pair(x * x, str+"*"));
            check.insert(x * x);
        }
        if(0 <= x + x && x + x <= limit && check.count(x + x) == 0){
            q.push(make_pair(x + x, str+"+"));
            check.insert(x + x);
        }
        if(0 <= x - x && x - x <= limit && check.count(x - x) == 0){
            q.push(make_pair(x - x, str+"-"));
            check.insert(x - x);
        }
        if(x != 0 && 0 <= x / x && x / x <= limit && check.count(x / x) == 0){
            q.push(make_pair(x / x, str+"/"));
            check.insert(x / x);
        }
    }
    cout << -1 << '\n';
    return 0;
}