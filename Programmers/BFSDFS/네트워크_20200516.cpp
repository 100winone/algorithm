#include <vector>
#include <iostream>
#include <queue>
#define MAX 201
using namespace std;
bool check[MAX];

void BFS(vector<vector<int>> computers, int n, int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        check[cur] = true;
        q.pop();
        for (int i = 0; i < n; ++i) {
            if(!check[i]){
                if(computers[cur][i] == 1){
                    q.push(i);
                }
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if(!check[i]){
            BFS(computers, n, i);
            answer++;
        }
    }
    return answer;
}
