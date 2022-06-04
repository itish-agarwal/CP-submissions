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
    
    int n;
    cin >> n;
    
    unordered_map<string, bool> here;
    
    int ans = 0;
    while(n--) {
        string s;
        cin >> s;
        if(here.count(s) == 0) {
            ++ans;
            here[s] = true;
        }
    }
    
    cout << ans << "\n";
}
