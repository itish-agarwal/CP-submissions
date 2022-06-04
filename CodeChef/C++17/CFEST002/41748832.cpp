#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res = (res*res) % mod;
  if(b % 2) {
    res = (res*a) % mod;
  }
  return res;
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, A, B, C;
    cin >> n >> A >> B >> C;
    int a = B - A;
    //r = (C-B)/(B-A);
    if(n == 1) {
      cout << A << " " << A << '\n';
    } else {
      --n;
      int p = power(C - B, n);
      int q = power(B - A, n);
      q = power(q, mod - 2);
      p = (p * q) % mod;
      p = (p - 1 + mod) % mod;
      
      int pp = C - B;
      int qq = B - A;
      qq = power(qq, mod - 2);
      pp = (pp * qq) % mod;
      pp = (pp - 1 + mod) % mod;
      
      pp = power(pp, mod - 2);
      p = (p * pp) % mod;
      
      p = (p * a) % mod;
      p = (p + A) % mod;
      cout << p << " ";      
      
      //find sum now;
      int answer = (n + 1) * A;
      answer %= mod;
      
      int x = power(C - B, n);
      int xx = power(power(B - A, n), mod - 2);
      x = (x * xx) % mod;
      x = (x - 1 + mod) % mod;
      x = (x * (C - B)) % mod;
      x = (x * power(C+A-2*B, mod - 2)) % mod;
      x = (x - n + mod) % mod;
      
      int w = a * (B - A);
      w %= mod;
      int ww = power(A + C - 2*B, mod - 2);
      w = (w * ww) % mod;
      
      x = (x * w) % mod;
      answer = (answer + x) % mod;
   
      cout << answer << '\n';
    }
  }
  return 0;
}
