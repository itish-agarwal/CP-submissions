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
    
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    if(a == 0) {
        cout << 1 << "\n";
    }else if(b == 0) {
        cout << 2 << "\n";
    }else if(c == 0) {
        cout << 3 << "\n";
    }else if(d == 0) {
        cout << 4 << "\n";
    }else{
        cout << 5 << "\n";
    }
    return 0;
    
}





























