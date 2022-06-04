#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int nax = 1e5 + 2;
vector<int> edges[nax];

void dp(int a, int pa, vector<ll>& dpb, vector<ll>& dpw) {
  if((int)edges[a].size() == 1 && edges[a][0] == pa) {
    dpb[a] = dpw[a] = 1;
    return;
  }
  ll answ = 1, ansb = 1;
  for(int b : edges[a]) {
    if(b == pa) {
      
    } else {
      dp(b, a, dpb, dpw);      
      answ *= (dpw[b] + dpb[b]);
      answ %= mod;
      ansb *= dpw[b];
      ansb %= mod;
    }
  }
  dpw[a] = answ;
  dpb[a] = ansb;
  return;    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }  
  vector<ll> dpb(n + 1), dpw(n + 1);  
  dp(1, -1, dpb, dpw);
  cout << (dpb[1] + dpw[1])%mod << '\n';
  return 0;
    
  
}
  
