/*2231 분해합 BruteForce 20200313*/
#include <stdio.h>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    int sum;
    int temp;
    for (int i = 1; i < num; ++i) {
        sum = i;
        temp = i;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == num){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}

