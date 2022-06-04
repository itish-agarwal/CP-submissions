#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
#define int long long

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
// void pr(int x)  { cout << x; }

template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);

template <class T, class V> void pr(const pair<T, V>& x) {
  cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
  for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

string L, R;
int len;

int dp[20][2][2][5];

int rec(int id, int lo, int hi, int rem) {
  if(id == len) {
    return rem == 0;
  }
  if(dp[id][lo][hi][rem] <= -1) {
    int ans = 0;
    int loLim = 0, hiLim = 9;
    if(hi) {
      hiLim = R[id] - '0';
    }
    if(lo) {
      loLim = L[id] - '0';
    }
    for(int i = loLim; i <= hiLim; i++) {
      if(true) {
        int newHigh = hi, newLow = lo;
        if(i != hiLim) {
          newHigh = 0;
        }
        if(i != loLim) {
          newLow = 0;
        }
        ans += rec(id + 1, newLow, newHigh, (rem + i) % 3);
      }
    }
    dp[id][lo][hi][rem] = ans;
  }
  return dp[id][lo][hi][rem];
}
void test_case() {
  cin >> L >> R;
  int n1 = L.size();
  int n2 = R.size();
  vector<string> ret{L};
  for(int i = n1; i < n2; i++) {
    string t = string(i, '9');
    string s = '1' + string(i, '0');      
    ret.push_back(t);
    ret.push_back(s);
  }
  ret.push_back(R);

  int ans = 0;
  for(int i = 1; i < (int) ret.size(); i += 2) {
    L = ret[i - 1], R = ret[i];
    len = L.size();

    memset(dp, -1, sizeof(dp));
    ans += rec(0, 1, 1, 0);
  } 

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}