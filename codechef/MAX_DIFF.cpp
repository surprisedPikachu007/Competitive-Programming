#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int C;
	cin >> C;

	int N[C], S[C], result[C];
	int i;
	for (i = 0; i < C; i++) {
    cin >> N[i] >> S[i];
	}

	int temp, max_diff;

	for(i=0; i<C; i++){

	if(N[i] < S[i]){
		temp = N[i];
		max_diff = N[i] - (S[i] - N[i]);
	}

	else if(N[i] > S[i]){
		max_diff = S[i];
	}

	else{
		max_diff = S[i];
	}

	cout << max_diff << endl;
	}

	return 0;
}