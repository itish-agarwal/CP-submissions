#include <bits/stdc++.h>

using namespace std;
#define int long long 
int C[100][100];

int ncr(int n, int r) {
  if(r==0 || r==n) {
    return 1;
  }
  if(C[n][r]>-1) {
    return C[n][r];
  }
  C[n][r] = ncr(n-1, r-1) + ncr(n-1, r);
  return C[n][r];
}
string f(int a, int b, int k) {
  if(k<=0) {
    cout<<a<<" " <<b<<endl;
    return "";
  }
  if(k==1) {
    string ans = "";
    while(a--) {
      ans.push_back('a');
    }
    while(b--) {
      ans.push_back('b');
    }
    return ans;
  } 
  int rem = ncr(a + b - 1, a - 1);
  if(rem < k) {
    string ans = "b";
    return ans + f(a, b - 1, k - rem);
  } else {
    string ans = "a";
    return ans + f(a - 1, b, k);
  }
} 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  memset(C, -1, sizeof(C));

  int A, B, K;
  cin >> A >> B >> K;

  cout << f(A, B, K) << '\n';
}