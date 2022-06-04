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
    int n;
    scanf("%d", &n);
    unordered_map<int, int> here;
    vector<int> a(n);
    int cnt = 0;
    for(int& x : a) {
        scanf("%d", &x);
        if(here.count(x) == 0) {
            here[x] = 1;
        }else{
            here[x]++;
        }
        if(x == 1) {
            ++cnt;
        }
    }
    
    if(cnt > 1) {
        printf("0\n");
        return 0;
    }
    
    if(cnt == 1) {
        printf("1\n");
        return 0;
    }
    
    int ans = 0;
    for(int x : a) {
        bool ok = true;
        for(int i = 1; i * i <= x; ++i) {
            if(x%i == 0) {
                int div1 = i;
                int div2 = x/i;
                if(div2 == x) {
                    if((here.count(div2) && here[div2] - 1 > 0) || (here.count(div1))) {
                        ok = false;
                    }
                } else {
                    if(here.count(div1) || here.count(div2)) {
                        ok = false;
                    }
                }
                
                if(ok == false) {
                    break;
                }
            }
        }
        if(ok) {
            ++ans;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
