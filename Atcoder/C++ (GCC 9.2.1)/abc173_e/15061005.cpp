#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;

void mul(long long& a, long long b) {
  a *= b;
  a = (a + mod*mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  int p = 0, z = 0, neg = 0;
  for(int i = 0; i < n; ++i) {
    if(a[i] > 0) p++;
    else if(a[i] == 0) z++;
    else neg++;
  }
  if(k > (n - z)) {
    cout << 0 << '\n';
    return 0;
  }
  if(z + neg == n && z > 0) {
    if(k > (n - z)) {
      cout << 0 << '\n';
    } else {
      //k <= neg
      if(k & 1) {
        cout << 0 << '\n';
      } else {
        long long prod = 1;
        for(int i = 0; i < k; ++i) {
          mul(prod, a[i]);
        }
        cout << prod << '\n';
      }
    }
    return 0;
  }
  if(a[n - 1] < 0) {
    if(k & 1) {
      long long prod = 1;
      for(int i = n - 1; i >= n - k; --i) {
        mul(prod, a[i]);
      }
      cout << prod << '\n';
    } else {
      long long prod = 1;
      for(int i = 0; i < k; ++i) {
        mul(prod, a[i]);
      }
      cout << prod << '\n';
    }
    return 0;
  }
  if(a[0] > 0) {
    long long prod = 1;
    for(int i = n - 1; i >= n - k; --i) {
      mul(prod, a[i]);
    }
    cout << prod << '\n';
    return 0;
  }
  if(a[0] == a[n - 1] && a[0] == 0) {
    cout << 0 << '\n';
    return 0;
  }
  if(p + z == n && z > 0) {
    long long prod = 1;
    for(int i = n - 1; i >= n - k; --i) {
      mul(prod, a[i]);
    }
    cout << prod << '\n';
    return 0;
  }
  if(k == p + neg) {
    if(neg & 1) {
      if(z > 0) {
        cout << 0 << '\n';
      } else {
        long long prod = 1;
        for(int i = 0 ; i < n; ++i) {
          mul(prod, a[i]);
        }
        cout << prod << '\n';
      }
    } else {
      long long prod = 1;
      for(int i = 0; i < n; ++i) {
        if(a[i] == 0) {
          
        } else {
          mul(prod, a[i]);
        }
      }
      cout << prod << '\n';
    }
    return 0;
  }  
  vector<long long> pre(n), suff(n);
  pre[0] = a[0];
  for(int i = 1; i < n; ++i) {
    long long x = pre[i - 1];
    mul(x, a[i]);
    pre[i] = x;
  }
  suff[n - 1] = a[n - 1];
  for(int i = n - 2; i >= 0; --i) {
    long long x = suff[i + 1];
    mul(x, a[i]);
    suff[i] = x;
  }
  int len = 0;
  while(len <= neg) {
    if(k - len <= p) {
      break;
    }
    len += 2;
  }  
  long long prod = (len == 0 ? 1 : pre[len - 1]);
  if(k > len) {
    mul(prod, suff[n - k + len]);
  }
  for(int L = len + 2; L <= min(k, neg); L += 2) {
    if(a[L - 1] * a[L - 2] > a[n - k + L - 2] * a[n - k + L - 1]) {
      prod = (L == 0 ? 1 : pre[L - 1]);
      if(n - k + L < n) {
        mul(prod, suff[n - k + L]);
      }
    } else {
      break;
    }
  }   
  cout << prod << '\n';
}  
  
  
  
  
  

