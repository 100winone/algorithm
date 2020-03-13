/*14891 톱니바퀴 Simulation recheck필요 20200313*/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main() {
    int n = 4;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    while (k--) {
        int no, dir;
        cin >> no >> dir;
        no -= 1;
        // 각각의 톱니는 동시에 회전해야 하기 때문에
        // 먼저, 각 톱니가 어떤 방향으로 회전해야 하는지 구하자
        vector<int> d(n);
        d[no] = dir;
        // 왼쪽 톱니를 연쇄적으로 구하고
        for (int i=no-1; i>=0; i--) {
            if (a[i][2] != a[i+1][6]) {
                d[i] = -d[i+1];
            } else {
                // 한 톱니가 회전하지 않으면
                // 그 톱니의 왼쪽에 있는 톱니도 회전하지 않는다.
                break;
            }
        }
        // 오른쪽 톱니를 연쇄적으로 구하고
        for (int i=no+1; i<n; i++) {
            if (a[i-1][2] != a[i][6]) {
                d[i] = -d[i-1];
            } else {
                // 한 톱니가 회전하지 않으면
                // 그 톱니의 오른쪽에 있는 톱니도 회전하지 않는다.
                break;
            }
        }
        for (int i=0; i<n; i++) {
            if (d[i] == 0) continue;
            if (d[i] == 1) {
                // 시계 방향 회전
                char temp = a[i][7];
                for (int j=7; j>=1; j--) {
                    a[i][j] = a[i][j-1];
                }
                a[i][0] = temp;
            } else if (d[i] == -1) {
                // 반시계 방향 회전
                char temp = a[i][0];
                for (int j=0; j<7; j++) {
                    a[i][j] = a[i][j+1];
                }
                a[i][7] = temp;
            }
        }
    }
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (a[i][0] == '1') {
            sum += pow(2, i);
        }
    }
    cout << sum << '\n';
    return 0;
}

//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//int main(){
//
//    int n = 4;
//    vector<string> graph(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> graph[i];
//    }
//    int k;
//    cin >> k;
//    while(k--){
//        int no, dir;
//        cin >> no >> dir;
//        no -= 1;
//        vector<int> d(n);
//        d[no] = dir; // 시계 - 1 반시계 - -1
//        for (int i = no - 1; i >= 0; --i) { // 왼쪽 톱니 먼저 구하기
//            if(graph[i][2] != graph[i + 1][6]){
//                d[i] = -d[i + 1]; // 현재거의 반대방향으로 돌리기
//            } else {
//                break;
//            }
//        }
//        for (int i = no + 1; i < n; ++i) {
//            if(graph[i - 1][2] != graph[i][6]){
//                d[i] = -d[i - 1];
//            } else{
//                break;
//            }
//        }
//        for (int i = 0; i < n; ++i) {
//            if(d[i] == 0) continue;
//            if(d[i] == 1){
//                char temp = graph[i][7];
//                for (int j = 7; j >= 1; --j) {
//                    graph[i][j] = graph[i][j - 1];
//                }
//                graph[i][0] = temp;
//            } else if(d[i] == -1){
//                char temp = graph[i][0];
//                for (int j = 0; j < 7; ++j) {
//                    graph[i][j] == graph[i][j + 1];
//                }
//                graph[i][7] = temp;
//            }
//        }
//    }
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        if(graph[i][0] == '1'){
//            sum |= (1 << i);
////            sum += pow(2, i);
//        }
//    }
//    cout << sum << '\n';
//    return 0;
//}
//
