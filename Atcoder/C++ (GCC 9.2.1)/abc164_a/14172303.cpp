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
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt = 0;
    while(1) {
        if(cnt & 1) {
            a -= d;
            if(a <= 0) {
                cout << "No\n";
                return 0;
            }
            //means it is Aoki's turn;
        }else{
            c -= b;
            if(c <= 0) {
                cout << "Yes\n";
                return 0;
            }
        }
        ++cnt;
    }
}
