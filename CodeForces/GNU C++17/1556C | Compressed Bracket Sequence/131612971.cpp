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
 
void test_case() {
  int N;
  cin >> N;
 
  vector<int> C(N);
  for(auto &c : C)
    cin >> c;
 
  vector<long long> heights{0};
  for(int i = 0; i < N; ++i) 
    heights.push_back(heights.back() + (i % 2 ? -C[i] : C[i]));
 
  long long min_so_far = 0, ans = 0;
  N = heights.size();
 
  vector<pair<long long, int>> valleys;
 
  for(int i = 0; i < N - 1; ++i) {
    min_so_far = min(min_so_far, heights[i]);
    if(heights[i] > heights[i+1]) {
      long long low = heights[i+1], high = heights[i];
      long long extra = high - max(min_so_far, low);
      while(!valleys.empty() && valleys.back().first > low) {
        ans += valleys.back().second;
        valleys.pop_back();
      }
      if(!valleys.empty() && valleys.back().first == low) {
        ans += valleys.back().second;
      }
      if(low >= min_so_far) {
        if(!valleys.empty() && valleys.back().first == low) {
          valleys.back().second++;
        }
        else {
          valleys.push_back({low, 1});
        }
      }
      ans += max(0LL, extra);
    }
  }
 
  debug(heights);
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
 
  while(tests--) 
    test_case();
}