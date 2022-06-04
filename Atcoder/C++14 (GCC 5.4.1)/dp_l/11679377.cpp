#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long int L;
//RECURSIVE SOLUTION
/*L mx(L* a, L n){        //function returns the max sum u can get by moving first
    if(n == 1){
        return a[0];
    }if(n == 2){
        return max(a[0], a[1]);
    }
    return max(a[0] + min(mx(a + 2, n - 2), mx(a + 1, n - 2)), a[n-1] + min(mx(a + 1, n - 2), mx(a, n - 2)));
}
*/

       
       
L answerDP(L* a, L n){
    
    
    vector<vector<L>> ans (n, vector<L> (n, 0));
    
    //ans[i][j] stores the answer for array starting from i and ending at j; hence j >= i;
    //only the right upper half of the square matrix is filled
    //ans[0][n-1] gives the answer
    
    //Base Case - i == j
    
    for(L i = 0; i<n; i++){
        ans[i][i] = a[i];
    }
    
    //Second base case - (j - i == 1)
    
    for(L i = 0; i<(n-1); i++){
        ans[i][i+1] = max(a[i], a[i+1]);
    }
    
    for(L count = 1; count <= (n-2); ++count){
        
        L i = 0;
        L j = count + 1;
        
        while(i < (n -  count - 1)){
            L op1 = a[i] + min(ans[i+2][j], ans[i+1][j-1]);
            L op2 = a[j] + min(ans[i+1][j-1], ans[i][j-2]);
            
            ans[i][j] = max(op1, op2);
            i++;
            j++;
        }
    }
  /*  for(L i = 0; i<n; i++){
        for(L j = 0; j<n; j++){
            cout << ans[i][j] << "     ";
        }cout << endl;
    }*/
    
    return ans[0][n-1];
    
}

int main() {
    L n, a[3005];
    scanf("%lld", &n);
    L s = 0;
    for(L i = 0; i<n; i++){
        scanf("%lld", &a[i]);
        s += a[i];
    }
    // cout << s << endl;
    // cout << 2*mx(a, n) - s << "\n";
    cout << 2*answerDP(a, n) - s << "\n";
}