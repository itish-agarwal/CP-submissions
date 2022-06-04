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
map<pair<int, int>, int> mp;
const int INF = 1e8 + 7;

string L, R;
int len, digit;

int dp[12][2][2][2];

int rec(int id, int lo, int hi, int seen) {
  if(id == len) 
    return seen == 0; 

  if(dp[id][lo][hi][seen] > -1)
    return dp[id][lo][hi][seen];

  int res = 0, loLim = 0, hiLim = 9;

  if(lo) loLim = L[id] - '0';
  if(hi) hiLim = R[id] - '0';

  for(int d = loLim; d <= hiLim; ++d) {
    int new_high = hi, new_low = lo;
    if(d != hiLim)
      new_high = 0;
    if(d != loLim)
      new_low = 0;
    
    if(d ^ digit) {
      res |= rec(id + 1, new_low, new_high, seen | (d == digit));
    }
    if(res == true) {
      break;
    }
  }

  return dp[id][lo][hi][seen] = res;
}

int is_missing(int a, int b) {
  L = to_string(a);
  R = to_string(b);

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

  int res = 0;

  for(int i = 1; i < (int) ret.size(); i += 2) {
    L = ret[i-1], R = ret[i], len = L.size();
    memset(dp, -1, sizeof(dp));
    res |= rec(0, 1, 1, 0);
    if(res) {
      return 1;
    }
  }

  return res;
}

void test_case() {
  int N;
  cin >> N >> digit;

  //if(mp.count({N, digit}) > 0) {
    //cout << mp[{N, digit}] << '\n';
    //return;
  //}
  
  int lo = 0, hi = 1, ans = INF;
    
  while(!is_missing(N, N + hi)) {
    hi *= 2;
  }
  
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(is_missing(N, N + mid)) {
      hi = mid - 1;
      ans = mid;
    }

    else {
      lo = mid + 1;
    }
  }

  //mp[{N, digit}] = ans;
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
