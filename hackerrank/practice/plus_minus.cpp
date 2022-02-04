#include <bits/stdc++.h>

using namespace std;

void plusMinus(vector<int> arr) {
    int p, n, z;
    p = n = z = 0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0){
            n++;
        }
        else if(arr[i]>0){
            p++;
        }
        else{
            z++;
        }
    }

    float p_f = (float)p/arr.size();
    float n_f = (float)n/arr.size();
    float z_f = (float)z/arr.size();

    printf("%.6f\n", p_f);
    printf("%.6f\n", n_f);
    printf("%.6f\n", z_f);
}

int main(){
    vector<int> arr = {-4, 3, -9, 0, 4, 1};
    plusMinus(arr);
    return 0;
}