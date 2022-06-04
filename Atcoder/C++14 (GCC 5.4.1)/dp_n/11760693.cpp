#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
const int nax = 405;
const ll INF = 1e18L + 5;
ll dp[nax][nax];
//dp[i][j] = the minimum total cost of combining interval i to j into one vertex
void min_self(ll& a, ll b){
    if(a > b){
        a = b;
    }
}
ll sum(int l, int r, vector<int>& a){
    ll s = 0;
    for(int i = l; i<=r; ++i){
        s += a[i];
    }
    return s;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<ll> b(n);
    for(int& x : a){
        scanf("%d", &x);
    }b[0] = a[0];
    for(int i = 1; i<n; ++i){
        b[i] = a[i];
        b[i] += b[i-1];
    }

    for(int l = n-1; l>=0; --l){
        for(int r = l; r<n; ++r){
            if(l == r){
                dp[l][r] = 0;
            }else{
                dp[l][r] = INF;
                for(int i = l; i<r; ++i){
                    min_self(dp[l][r], dp[l][i] + dp[i+1][r] + (l == 0 ? b[r] : b[r] - b[l - 1]));
                }
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}



// void min_self(int& a, int b){
//     a = min(a, b);
// }

// int mCost(vector<int>& a, int n){
//     if(n == 1){
//         return 0;
//     }if(n == 2){
//         return a[0] + a[1];
//     }

//     int ans = INT_MAX;

//     for(int i = 0; i<(n-1); i++){
//         vector<int> b(n);
//         b = a;
//         int cost = b[i] + b[i+1];
//         b[i+1] += b[i];
//         b.erase(b.begin() + i);

//         min_self(ans, cost + mCost(b, n-1));
//     }
//     return ans;
// }