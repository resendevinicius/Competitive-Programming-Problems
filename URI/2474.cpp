#include <bits/stdc++.h>

using namespace std;

int ans[] = {1,2,4,6,8,14,18,20,22,34,36,44,52,72,86,96,112,114,118,132,148,154,180,210,220,222,234,248,250,282};
int v[] = {3,5,11,29,97,127,541,907,1151,1361,9587,15727,19661,31469,156007,360749, 370373, 492227, 1349651, 1357333, 2010881, 4652507, 17051887, 20831533, 47326913, 122164969, 189695893, 191913031, 387096383, 436273291 };
int main(){

	int n;
	int N = 30;
	while(scanf("%d",&n) != EOF){
		printf("%d\n", ans[upper_bound(v, v + N, n) - v - 1]);
	}

	return 0;
}