#include "bits/stdc++.h"
#pragma optimize("unroll-loops");
#pragma optimize("Ofast");
// #include "pch.h"    
using namespace std;

#ifdef DEBUG_BUILD
#  define DEBUG(x) cerr << x
#else
#  define DEBUG(x) do {} while (1)
#endif

#define imie(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)

using ll = long long;
const ll nax = 1e7 + 10;
const int mod = 1e9 + 7;
vector<int> primes;

int abs(int a, int b) {
    if(a > b) {
        return a - b;
    }
    return b - a;
}

int main() {
    int x, n;
    cin >> x >> n;
    unordered_map<int, bool> here;
    while(n--) {
        int p;
        cin >> p;
        here[p] = true;
    }
    
    
    int mn = INT_MAX;
    int ans;
    
    for(int a = -1000; a <= 1000; ++a) {
        if(here.count(a) == 0) {
            if(abs(a, x) < mn) {
                mn = abs(a, x);
                ans = a;
            }
        }
    }
    
    cout << ans << "\n";
}
    
    
    
    
    












