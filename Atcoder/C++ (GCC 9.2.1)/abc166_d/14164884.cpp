#include "bits/stdc++.h"
#pragma optimize("unroll-loops");
#pragma optimize("Ofast");
//#include "pch.h"    
using namespace std;
unordered_map<int, bool> here;
 
using ll = long long;
const int nax = 1e5 + 10;
vector<int> edges[nax];

int main() {
    
    ll x;
    cin >> x;
    
    for(ll a = -1000; a <= 1000; ++a) {
        for(ll b = -1000; b <= 1000; ++b) {
            ll aa = a*a*a*a*a;
            ll bb = b*b*b*b*b;
            if(aa - bb == x) {
                cout << a << " " << b << "\n";
                return 0;
            }
        }
    }
}
