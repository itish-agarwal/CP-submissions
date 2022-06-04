#include <bits/stdc++.h>

using namespace std;
#define int long long 

#ifndef ONLINE_JUDGE
#define debarr(a, n) cerr << #a << ": ["; for(int i = 0; i < n; i++) cerr << a[i] << " "; cerr<<"]\n";
#define pr(...) dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T> ostream &operator<<(ostream &os, const pair<S,T> &p){return os <<" (" << p.first << ", "<< p.second << ")";}
template<class T> ostream &operator<<(ostream &os, const vector<T>& p){ os << "["; for(auto& it : p) os << it <<" "; return os << "]";}
template<class T> ostream &operator<<(ostream &os, const set<T>& p){ os << "["; for(auto&it : p) os << it << " "; return os << "]";}
template<class T> ostream &operator<<(ostream &os, const multiset<T>& p){ os << "["; for(auto&it : p) os << it << " "; return os << "]";}
template<class S,class T> ostream &operator<<(ostream &os, const map<S,T>& p){ os << "["; for(auto&it : p) os << it <<   " "; return os << "]";}
template<class T>void dbs(string str,T t){ cerr << str << ": "<< t << '\n';}
template<class T,class...S> void dbs(string str, T t, S... s){ int idx = str.find(','); cerr << str.substr(0,idx) << ": " << t << ", "; dbs(str.substr(idx+1), s...); }
#else
#define pr(...) { }
#define debarr(a,n) { }
#endif

const int INF = 2e17 + 8;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("Output", "w", stderr);
  #endif
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int k = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < i; j++) {
        cout << "_ ";
      }
      if(i > 0) {
        cout << "_";
      }
      for(int j = k; j < k + i; j++) {
        cout << (char)(j + 'a');
      }
      k += i;
      if(i == 0) {
        cout << 'a';
        k++;
      }
      cout << '\n';
    }
  }
}
