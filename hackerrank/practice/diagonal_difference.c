#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int d1 = 0, d2 = 0, j=1;

    for(int i=0; i<arr_rows; i++){
        d1 += arr[i][i];
        d2 += arr[i][arr_columns-j];
        j++;
    }

    return abs(d1-d2);
}

int main(){
    int arr_rows, arr_columns;
    scanf("%d %d", &arr_rows, &arr_columns);

    int** arr = (int**)malloc(sizeof(int*)*arr_rows);
    for(int i=0; i<arr_rows; i++){
        arr[i] = (int*)malloc(sizeof(int)*arr_columns);
    }

    for(int i=0; i<arr_rows; i++){
        for(int j=0; j<arr_columns; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(arr_rows, arr_columns, arr);
    printf("%d\n", result);

    return 0;
}