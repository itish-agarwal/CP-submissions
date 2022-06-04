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
const int nax = 5e3 + 10;

vector<int> primes;
ll lcm(ll a, ll b) {
    return (a*b)/__gcd(a, b);
}

int main() {
    
    ll a;
    double b;
    cin >> a >> b;
    b *= 100;
    b += 0.00001;
    a = (a * (ll)b)/100;
    cout << a << "\n";
}
