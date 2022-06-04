#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for(int &x : a){
        scanf("%d", &x);
    }
    vector<bool> dp(k + 1);
    
    for(int i = 0; i<=k; i++){
        for(int x : a){
            if(i >= x && !dp[i - x]){
                dp[i] = true;
            }
        }
    }
    
    
    puts(dp[k] ? "First" : "Second");
}