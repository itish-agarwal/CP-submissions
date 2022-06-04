#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long int L;
const L mod = 1000000007;

L CountPathsDP(L grid[][1005], L h, L w){
    
    vector<vector<L>> f(h + 1, vector<L> (w + 1, 0));
    
    f[h][w] = 1;
    //f[i][j] denotes the answer for starting from i, j;
    
    for(L i = h; i>=1; i--){
        for(L j = w; j>=1; j--){
            if(i==h && j==w){
                continue;
            }
            bool right, down;
            right = down = true;
            
            if(i == h || grid[i+1][j] == 1){
                down = false;
            }
            
            if(j == w || grid[i][j+1] == 1){
                right = false;
            }
            
            L ans;
            
            if(right && down){
                ans = (f[i+1][j]%mod) + (f[i][j+1]%mod);
                ans %= mod;
            }else if(right){
                ans = f[i][j+1]%mod;
                ans %= mod;
            }else if(down){
                ans = f[i+1][j]%mod;
                ans %= mod;
            }else{
                ans = 0;
            }
            
            f[i][j] = ans;
            f[i][j] %= mod;
        }
    }
    
    return f[1][1];
}
int main(){
    L h, w;
    scanf("%d%d", &h, &w);
    
    L grid[1005][1005];
    
    for(L i = 1; i<=h; i++){
        for(L j = 1; j<=w; j++){
            char x; cin >> x;
            if(x == '#'){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }
        }
    }
    cout << CountPathsDP(grid, h, w) << "\n";
    
}
    
    
    
    
    







