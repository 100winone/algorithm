/*9095 1,2,3 더하기 N중 for문 BruteForce 20200309*/
#include <stdio.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int cnt = 0;
        int n;
        scanf("%d", &n);
        for (int i1 = 1; i1 <= 3; ++i1) {
            if(i1 == n){
                cnt += 1;
            }
            for (int i2 = 1; i2 <= 3; ++i2) {
                if(i1 + i2 == n){
                    cnt += 1;
                }
                for (int i3 = 1; i3 <= 3; ++i3) {
                    if(i1 + i2 + i3 == n){
                        cnt += 1;
                    }
                    for (int i4 = 1; i4 <= 3; ++i4) {
                        if(i1 + i2 + i3 + i4 == n){
                            cnt += 1;
                        }
                        for (int i5 = 1; i5 <= 3; ++i5) {
                            if(i1 + i2 + i3 + i4 + i5 == n){
                                cnt += 1;
                            }
                            for (int i6 = 1; i6 <= 3; ++i6) {
                                if(i1 + i2 + i3 + i4 + i5 + i6 == n){
                                    cnt += 1;
                                }
                                for (int i7 = 1; i7 <= 3; ++i7) {
                                    if(i1 + i2 + i3 + i4 + i5 + i6 + i7 == n){
                                        cnt += 1;
                                    }
                                    for (int i8 = 1; i8 <= 3; ++i8) {
                                        if(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 == n){
                                            cnt += 1;
                                        }
                                        for (int i9 = 1; i9 <= 3; ++i9) {
                                            if(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 == n){
                                                cnt += 1;
                                            }
                                            for (int i10 = 1; i10 <= 3; ++i10) {
                                                if(i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 == n){
                                                    cnt += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}