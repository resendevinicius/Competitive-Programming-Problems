#include <bits/stdc++.h>

using namespace std; 
int main()
{
	int n,m; ios_base::sync_with_stdio(0); cin.tie(0);

	while( cin >> n >> m, n|m){
		string a;
		m--;  
		vector<string> v;
		for(int i = 0; i < n; i++) cin >> a, v.push_back(a);

		string ans;
		for(int i = 0; i < n; i++){
			if(m < i + 1) {
				ans = v[m];
				break;
			}
			else m -= i + 1;
		}
		cout << ans << endl;

	}
	
	return 0;
}
