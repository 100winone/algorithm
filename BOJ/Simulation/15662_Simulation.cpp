/*15662 톱니바퀴2 Simulation 20200313*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
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
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i][0] == '1') {
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}

