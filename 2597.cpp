#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	long long int n;
	long long int ant = 1;
	cin >> n;
	for(int i = 0; i <= n; i++){
		if(i * i > n){
			cout << n - (long long) sqrt(ant) << endl;
			return 0;
		}
		ant = i * i;
	}

	return 0;
}