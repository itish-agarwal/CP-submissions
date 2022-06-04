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
const int nax = 1e6 + 10;

vector<int> primes;
ll lcm(ll a, ll b) {
    return (a*b)/__gcd(a, b);
}

vector<bool> prime(nax, true);

ll f(ll n) {
    ll ans = 0;
    while(ans*(ans + 1)/2 < n) {
        ++ans;
    }
    return ans;
}

int main() {
    
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
     
    for(int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        ans[x]++;
    }
    
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
