#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void remove_zeroes_and_stars(char* str){
    int i = 0;
    int j = 0;
    while(str[i] != '\0'){
        if(str[i] != '0'){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    i = 0;
    j = 0;
    while(str[i] != '\0'){
        if(str[i] != '*'){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

char* decryptpassword(char* s){
    int n = strlen(s);
    int i,j;
    i=0;
    int last_zero;

    while(i<n-1){
        if(isdigit(s[i]) && s[i]!='0'){
            j=i+1;
            while(s[j]!='\0'){
                if(s[j]=='0'){
                    last_zero = j;
                }
                j++;
            }
            if(s[last_zero]=='0'){
                swap(&s[i],&s[last_zero]);
            }
        }

        /*else if(isalpha(s[i])){
            if(isalpha(s[i+1])){
                if(s[i+2]=='*'){
                    if(isupper(s[i]) != isupper(s[i+1])){
                        swap(&s[i], &s[i+1]);
                    }
                }
            }
        }*/

        else if(isalpha(s[i]) && isalpha(s[i+1]) && s[i+2]=='*'){
            if(isupper(s[i]) != isupper(s[i+1])){
                swap(&s[i], &s[i+1]);
            }
        }

        i++;
    }

    return s;
}

int main(){
    char s[] = "51Pa*0Lp*0e";
    printf("%s\n", decryptpassword(s));
    remove_zeroes_and_stars(s);
    printf("%s\n", s);

    printf("\n");
    char s1[] = "pTo*Ta*O";
    printf("%s\n", decryptpassword(s1));
    remove_zeroes_and_stars(s1);
    printf("%s\n", s1);

    return 0;
}