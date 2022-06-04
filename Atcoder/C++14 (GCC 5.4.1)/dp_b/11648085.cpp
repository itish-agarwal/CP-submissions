#include <bits/stdc++.h>
#include <stdio.h>
#include <climits>

using namespace std;
inline int abs(int a, int b){
    if(a > b) return a - b;
    return b - a;
}
/*int FrogDP(int* a, int n){    //assume a is indexed from 1 
    
    int* ans = new int[n+1]; //a[i] denotes the answer for i heights
    ans[1] = 0; ans[2] = abs(a[1], a[2]);
    
    for(int i = 3; i<=n; i++){
        int option1 = abs(a[i], a[i-1]) + ans[i-1];
        int option2 = abs(a[i], a[i-2]) + ans[i-2];
        ans[i] = min(option2, option1);
    }
    
    return ans[n];
}*/

int FrogDPK(int* a, int n, int k){
    
    int* ans = new int[n+1];
    ans[1] = 0;
    for(int i = 2; i <= (k+1); i++){
        ans[i] = abs(a[1], a[i]);
    }
    
    
    for(int i = k + 2; i<=n; i++){
        int m = INT_MAX;
        for(int j = i - 1; j>=(i - k); j--){
            m = min(m, abs(a[i], a[j]) + ans[j]);
        }
        ans[i] = m;
    }
    
    return ans[n];
}
int main() {
    int n, k, a[100002];
    cin >> n >> k;
    for(int i = 1; i<=n; i++) cin >> a[i];
    cout << FrogDPK(a, n, k) << endl;
}
    