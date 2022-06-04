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
    int n, e;
    cin >> n >> e;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    
    int ans = 0;
    while(e--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    
    for(int i = 1; i <= n; ++i) {
        if(edges[i].size() == 0) {
            ++ans;
        }else{
            bool ok = true;
            for(int x : edges[i]) {
                if(h[x] >= h[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ++ans;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
