#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        
        int n; cin >> n;
        
        int a[n];
        int b[n];
        vector<int> v;
        
        for(int i = 0; i < n; i++) {
            
            cin >> a[i] >> b[i];
            v.push_back(a[i]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            
            int x = a[i] - b[i];
            int y = a[i] + b[i];
           
            vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), x);
            int lo = it1 - v.begin();        
            
                    
            vector<int>::iterator it2 = upper_bound(v.begin(), v.end(), y);
            int hi = it2 - v.begin();
            
            
            ans = max(ans, hi - lo);
        }
        cout << ans << endl;
    }
    
    return 0;
}
