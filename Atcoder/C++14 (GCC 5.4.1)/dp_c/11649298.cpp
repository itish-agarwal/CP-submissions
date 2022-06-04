#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int f(int a[][4], int n){
    
    int** f = new int*[n+1];
    for(int i = 0; i<=n; i++){
        f[i] = new int[4];
    }
    f[n][1] = a[n][1];
    f[n][2] = a[n][2];
    f[n][3] = a[n][3];
    // f[i][j] denotes the answer when we do jth activity on ith day
    for(int i = n-1; i>=1; i--){
        f[i][1] = a[i][1] + max(f[i+1][2], f[i+1][3]);
        f[i][2] = a[i][2] + max(f[i+1][1], f[i+1][3]);
        f[i][3] = a[i][3] + max(f[i+1][1], f[i+1][2]);
    }
    
    return max(f[1][1], max(f[1][2], f[1][3]));
}
int main() {
    int n; cin >> n;
    int grid[100002][4];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=3; j++){
            cin >> grid[i][j];
        }
    }
    cout << f(grid, n) << "\n";
}