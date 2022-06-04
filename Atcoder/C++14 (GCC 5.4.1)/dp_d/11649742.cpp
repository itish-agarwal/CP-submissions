#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long int L;
L f1(L n, L W, L* w, L* v){
    
    L** f = new L*[n+1];
    for(L i = 0; i<=n; i++){
        f[i] = new L[W+1];
    }
    //f[i][j] denotes the answer for array starting from ith index and W = j;
    
    for(L j = 1; j<=W; j++){
        if(w[n] <= j){
            f[n][j] = v[n];
        }else f[n][j] = 0;
    }
    
    for(L i = 0; i<=n; i++){
        f[i][0] = 0;
    }
    
    for(L i = n-1; i>=1; i--){
        for(L j = 1; j<=W; j++){
            
            L x, y; x = y = -1;
            
            if(w[i] <= j){
                x = v[i] + f[i+1][j - w[i]];
            }
            
            y = f[i+1][j];
            
            f[i][j] = max(x, y);
        }
    }
    return f[1][W];
}
int main(){
    L n, W;
    cin >> n >> W;
    L w[100002], v[100002];
    for(L i = 1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    
    cout << f1(n, W, w, v) << "\n";
}