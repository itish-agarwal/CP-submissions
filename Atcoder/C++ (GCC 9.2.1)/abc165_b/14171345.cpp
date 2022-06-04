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
    
    ll bal = 100;
    ll answer = 0;
    while(1) {
        if(bal >= x) {
            break;
        }
        bal *= (1.01);
        ++answer;
    }
    
    cout << answer << "\n";
}
