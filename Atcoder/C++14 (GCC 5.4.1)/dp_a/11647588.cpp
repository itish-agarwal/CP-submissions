#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
inline int abs(int a, int b){
    if(a > b) return a - b;
    return b - a;
}
int FrogDP(int* a, int n){    //assume a is indexed from 1 
    
    int* ans = new int[n+1]; //a[i] denotes the answer for i heights
    ans[1] = 0; ans[2] = abs(a[1], a[2]);
    
    for(int i = 3; i<=n; i++){
        int option1 = abs(a[i], a[i-1]) + ans[i-1];
        int option2 = abs(a[i], a[i-2]) + ans[i-2];
        ans[i] = min(option2, option1);
    }
    
    return ans[n];
}


int main() {
    int n, a[100002];
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    cout << FrogDP(a, n) << endl;
}
    