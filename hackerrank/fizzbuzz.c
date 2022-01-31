#include <stdio.h>

void fizzBuzz(int n) {
    for(int i=1; i<=n; i++){
        if(i%3 == 0 && i%5 == 0){
            printf("%d %d FizzBuzz\n", i/3, i/5);
        }
        
        else if(i%3 == 0){
            if(i%5 != 0){
                printf("%d %d Fizz\n", i/3, i/5);
            }
        }
        
        else if(i%5 == 0){
            if(i%3 != 0){
                printf("%d %d Buzz\n", i/3, i/5);
            }
        }
        
        else {
        printf("%d %d %d\n", i/3, i/5, i);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    fizzBuzz(n);
    return 0;
}