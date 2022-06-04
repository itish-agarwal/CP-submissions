#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  vector<int> a(n + 1, -1);

  for(int i = 1; i < n; i++) {
    if(s[i-1]=='>' && s[i]=='<') {
      a[i] = 0;
    }
  }

  if(s[0]=='<') {
    a[0] = 0;
  }
  if(s[n-1]=='>') {
    a[n] = 0;
  }

  vector<int> in;

  for(int i = 0; i <= n; i++) {
    if(a[i]==0) {
      in.push_back(i);
    }
  }

  for(int i = 1; i < in.size(); i++) {
    
    int l = in[i-1], r = in[i];
  
    r--;

    int k = 1;
    int in = -1;
    for(int j = l + 1; j <= r; j++) {
      if(s[j]=='<') {
        a[j] = k;
        k++;
      } else {
        in = j;
        break;
      }
    }
    // cout<<in<<endl;
    int p = 1;
    for(int j = r; j >= l; j--) {
      if(s[j]=='>') {
        a[j] = p;
        p++;
      } else {
        break;
      }
    } 
    if(in>-1) {
      a[in] = max(k, p - 1);
    }
  }

  int z = -1;
  for(int i = 0; i <= n; i++) {
    if(a[i]==0) {
      z = i;
      break;
    }
  }

  int k = 1;
  for(int i = 0; i <= n; i++) {
    if(a[i]==-1 && i>z) {
      a[i] = k;
      k++;
    }
  }

  k = 1;
  for(int i = n; i >= 0; i--) {
    if(a[i]==-1) {
      a[i] = k;
      k++;
    }
  }
  int ans = 0;
  for(int x : a) {
    ans += x;
  }

  cout << ans << '\n';
  return 0;
}