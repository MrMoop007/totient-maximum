#include <stdio.h>
#include<stdbool.h>

int phi_function(int n){
    int result = n;
    int p;
    for(p = 2; p*p <= n; p++){
        if(n%p == 0){
            while(n%p == 0){
                n /= p;
            }
            result -= result/p;
        }
    }

    if(n>1){
        result -= result/n;
    }

    return result;
}

int main(){
    int i;
    float best_so_far = 0.0;
    int best_index_so_far;
    float current;
    int bound = 1000000;
    for(i = bound; i > 1; i--){
        current = (float)i/phi_function(i);
        if(current > best_so_far){
            best_index_so_far = i;
            best_so_far = current;
        }
    }
    printf("The greatest possible value of n/phi(n) for n<=%d is %f, which is equivalent to %d/phi(%d)\n", bound, best_so_far, best_index_so_far, best_index_so_far);
    return 0;
}