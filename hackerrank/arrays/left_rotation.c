#include <stdio.h>
#include <stdlib.h>


int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
    *result_count = arr_count;
    int start;
    while((start = (arr_count - d)) < 0);
    
    int l = 0, r= 0, res = 0;
    int i;
    int rsize = arr_count - start;
    int lsize = arr_count - rsize;
    int left[lsize], right[rsize], result[arr_count];
    
    for(i=0; i<rsize; i++) {
        right[r] = arr[i];
        r++;
    }
    
    for(i=i; i<arr_count; i++) {
        left[l] = arr[i];
        l++;
    }
    
    for(int i=0; i<lsize; i++) {
        result[res] = left[i];
        res++;
    }
    
    for(int i=0; i<rsize; i++) {
        result[res] = right[i];
        res++;
    }
        
    for(int i=0; i<arr_count; i++) {
        printf("%d ",result[i]);
    }
    printf("\n");
    
    for(int i=0; i<arr_count; i++) {
        arr[i] = result[i];
    }
    
    return arr;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int result_count;
    int* result = rotateLeft(d, n, arr, &result_count);
    
    for(int i=0; i<result_count; i++) {
        printf("%d ", result[i]);
    }
}