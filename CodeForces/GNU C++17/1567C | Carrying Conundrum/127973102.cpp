#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);
 
  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);
 
  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
 
void test_case() {
  int N;
  cin >> N;
 
  map<int, int> mp;
 
  for(int a = 0; a < 10; ++a)
    for(int b = 0; b < 10; ++b)
      mp[a + b] += 1;
 
  vector<int> dec(10);
  int K = N;
  
  for(int a = 0; a < 10; ++a) {
    dec[a] = K % 10;
    K /= 10;
  }   
 
  vector<vector<long long>> dp(10, vector<long long> (2));
 
  dp[0][0] = mp[dec[0]];
  dp[1][0] = mp[dec[1]];
  dp[0][1] = mp[dec[0] + 10];
  dp[1][1] = mp[dec[1] + 10];
 
  if(N < 100) {
    cout << mp[dec[0]] * mp[dec[1]] - 2 << '\n';
  }
 
  else {
    for(int i = 2; i < 10; ++i) {
      dp[i][0] = mp[dec[i]] * dp[i-2][0] + mp[dec[i]-1] * dp[i-2][1];
      dp[i][1] = mp[dec[i]+10] * dp[i-2][0] + mp[dec[i]+9] * dp[i-2][1];
    }
 
    cout << dp[9][0] * dp[8][0] - 2 << '\n';
  }
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests;
  cin >> tests;
  while(tests--)
    test_case();
 
}