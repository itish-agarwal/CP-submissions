#include <stdio.h>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

string lcsStringDPDP(string x, string y){
    int x1, y1;
    x1 = x.size(); 
    y1 = y.size();
    
    vector<vector<int>> f(x1 + 1, vector<int> (y1 + 1, 0));
    
    for(int j = 0; j<=y1; j++){
        f[x1][j] = 0;
    }
    for(int i = 0; i<=x1; i++){
        f[i][y1] = 0;
    }
    for(int i = x1-1; i>=0; i--){
        for(int j = y1-1; j>=0; j--){
            if(x[i] == y[j]){
                f[i][j] = 1 + f[i+1][j+1];
            }
            else{
                f[i][j] = max(f[i+1][j], f[i][j+1]);
            }
        }
    }
    
    string ans = "";
    // cout << x << " " << y << endl;
    int i, j; i = j = 0;
    // cout << x[i] << " " <<y[j] << endl;
    while(i < x1 && j < y1){
        if(x[i] == y[j]){
            // i++; j++;
            ans.push_back(x[i]);
            i ++; j ++;
            // cout << ans << endl;
        }
        else if(f[i][j+1] > f[i+1][j]){
            j++;
        }else i++;
    }
    
  //  reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << lcsStringDPDP(a, b) << endl;
    // cout << a << " " << b << endl;
}
    
    
    
    
