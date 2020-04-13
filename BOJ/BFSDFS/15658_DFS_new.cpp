/*15658 연산자 끼워넣기2 DFS !! 20200310*/
#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> arr;
int minValue = 1000000005;
int maxValue = -1000000005;
void DFS(int plus, int minus, int multiple, int div, int sum, int index){
    if(index == N){
        if(sum < minValue) minValue = sum;
        if(sum > maxValue) maxValue = sum;
        return;
    }
    if(plus > 0) DFS(plus - 1, minus, multiple, div, sum + arr[index], index + 1);
    if(minus > 0) DFS(plus, minus - 1, multiple, div, sum - arr[index], index + 1);
    if(multiple > 0) DFS(plus, minus, multiple - 1, div, sum * arr[index], index + 1);
    if(div > 0) DFS(plus, minus, multiple, div - 1, sum / arr[index], index + 1);
}
int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    int plus, minus, multiple, div;
    scanf("%d %d %d %d", &plus, &minus, &multiple, &div);
    DFS(plus, minus, multiple, div, arr[0], 1);
    printf("%d\n", maxValue);
    printf("%d\n", minValue);

    return 0;
}
