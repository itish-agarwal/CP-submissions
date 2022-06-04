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
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll& x : a) {
        cin >> x;
    }
    
    ll answer = 0;
    
    unordered_map<ll, ll> here1, here2;
    for(int i = 0; i < n; ++i) {
        if(here1.count(i - a[i])) {
            here1[i - a[i]]++;
        }else{
            here1[i - a[i]] = 1;
        }
        
        if(here2.count(i + a[i])) {
            here2[i + a[i]]++;
        }else{
            here2[i + a[i]] = 1;
        }
    }
    
    for(int i = 0; i < n; ++i) {
        ll pos = i - a[i];
        if(here2.count(pos)) {
            
            answer += (here1[pos] * here2[pos]);
            here1[pos] = here2[pos] = 0;
            if(a[i] == 0) {
                --answer;
            }
        }
    }
    
    cout << answer << "\n";
}
