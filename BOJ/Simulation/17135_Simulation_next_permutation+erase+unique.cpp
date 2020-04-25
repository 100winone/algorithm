/*17135 캐슬 디펜스 Simulation + next_permutation 20200424*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 15

using namespace std;

int n, m, d;
int map[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    vector<pair<int, int>> enemy; // 적 위치
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 1){
                enemy.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> archer; // 궁수
    for (int i = 0; i < m - 3; ++i) {
        archer.push_back(0); // 앞에다 0 박고
    }
    for (int i = 0; i < 3; ++i) {
        archer.push_back(1); // 뒤에 세개에 1 넥퍼뮤 쓰려구
    }

    int res = 0;
    do {
        int cnt = 0;
        vector<pair<int, int>> temp = enemy; // 적 좌표 복사
        vector<int> v;
        for (int i = 0; i < archer.size(); ++i) {
            if(archer[i] == 1){
                v.push_back(i); // 현재 궁수 위치
            }
        }
        while(!temp.empty()){
            int y = n;
            vector<int> target;

            // 궁수 동시공격
            for (int i = 0; i < v.size(); ++i) {
                int x = v[i];
                int idx = 0;
                int enemyX = temp[0].second;
                int dist = abs(y - temp[0].first) + abs(x - temp[0].second);
                for (int j = 1; j < temp.size(); ++j) {
                    int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second);

                    if(dist > tempDist){ // 더 가까운 적
                        enemyX = temp[j].second;
                        dist = tempDist;
                        idx = j;
                    } else if(dist == tempDist && enemyX > temp[j].second){
                        enemyX = temp[j].second;
                        idx = j;
                    }
                }

                if(dist <= d){
                    target.push_back(idx);
                }
            }
            target.erase(unique(target.begin(), target.end()), target.end()); // 중복된 애들은 지우기
            sort(target.begin(), target.end()); // temp 즉 , 적의 위치 인덱스가 들어가 있음

            int shoot = 0; // index 없애면 한칸씩 땡겨야 하므로 필요한 변수

            for (int i = 0; i < target.size(); ++i) {
                temp.erase(temp.begin() + (target[i] - shoot++));
                cnt++;
            }

            if(temp.empty()){
                break;
            }
            // 칸 이동 아래로
            vector<pair<int, int>> copyTemp;
            for (int i = 0; i < temp.size(); ++i) {
                if(temp[i].first < n - 1){
                    copyTemp.push_back(make_pair((temp[i].first + 1), (temp[i].second)));
                }
            }

            temp = copyTemp;
        }
        res = max(res, cnt);
    } while(next_permutation(archer.begin(), archer.end()));

    cout << res << '\n';
    return 0;
}