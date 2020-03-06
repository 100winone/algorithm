/*1748 수 이어쓰기 1 BruteForce 20200307*/
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int num;
    long long sum = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; ++i) {
        if(num > pow(10, i)){
            sum = sum + (pow(10, i) - pow(10, i - 1)) * i;
        }
        else {
            sum = sum + (num - pow(10, i - 1) + 1) * i;
            printf("%lld\n", sum);
            return 0;
        }
    }
}