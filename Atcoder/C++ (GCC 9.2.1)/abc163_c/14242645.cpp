#include "bits/stdc++.h"
#pragma optimize("unroll-loops");
#pragma optimize("Ofast");
//#include "pch.h"    
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

int main() {
    ll answer = 0;
    ll k; cin >> k;
    
    for(ll a = 1; a <= k; ++a) {
        for(ll b = 1; b <= k; ++b) {
            for(ll c = 1; c <= k; ++c) {
                answer += __gcd(a, __gcd(b, c));
            }
        }
    }
    cout << answer << "\n";
}
