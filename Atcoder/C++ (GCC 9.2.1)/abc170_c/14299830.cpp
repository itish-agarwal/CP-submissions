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

int main() {
    
    int x, legs;
    cin >> x >> legs;
    
    
    for(int a = 0; a <= 1000; ++a) {
        for(int b = 0; b <= 1000; ++b) {
            if(2*a + 4*b == legs) {
                if(a + b == x) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    
    cout << "No\n";
}



















