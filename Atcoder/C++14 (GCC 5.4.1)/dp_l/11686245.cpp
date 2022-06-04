#include "bits/stdc++.h"
#include <stdio.h>

using namespace std;

using ll = long long;

const int nax = 3005;

ll dp[nax][nax];

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a[i]);
    }
    //dp[0][n-1] stores the answer
    for(int L = n - 1; L >=0; --L){
        for(int R = L; R < n; ++R){
            if(L == R){
                dp[L][R] = a[L];
            }else{
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
            }
        }
    }
    printf("%lld", dp[0][n-1]);
}