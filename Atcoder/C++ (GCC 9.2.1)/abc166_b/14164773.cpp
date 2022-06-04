#include "bits/stdc++.h"
#pragma optimize("unroll-loops");
#pragma optimize("Ofast");
//#include "pch.h"    
using namespace std;
unordered_map<int, bool> here;
 
using ll = long long;
const int nax = 5e5 + 2;
const ll mod = 1e9 + 7;

int main() {
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1, -1);
    
    while(k--) {
        int d;
        cin >> d;
        while(d--) {
            int snuke;
            cin >> snuke;
            a[snuke] = 1;
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == -1) {
            ++ans;
        }
    }
    
    cout << ans << "\n";
}
