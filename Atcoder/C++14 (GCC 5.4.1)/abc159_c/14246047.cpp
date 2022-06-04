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

ll abs(ll a, ll b) {
    if(a > b) {
        return a - b;
    }
    return b - a;
}

ll min(ll a, ll b) {
    if(a < b) {
        return a;
    }
    return b;
}
int main() {
    
    int l;
    cin >> l;
    
    double a = (l * 1.0) / 3;
    a *= (a*a);
    
    printf("%0.10lf\n", a);
}
    
