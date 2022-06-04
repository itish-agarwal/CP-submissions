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
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
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
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
const int64_t INF = (int64_t) 2e18 + 9;
 
int64_t ceil_div(int64_t a, int64_t b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int N;
   cin >> N;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   int64_t ans = INF;
 
   for (int i = 0; i < N; ++i) {
      int64_t p = 0, val = 0;
      for (int j = i + 1; j < N; ++j) {
         val += 1;
         int64_t t = ceil_div (val, A[j]);
         val = t * A[j];
         p += t;
      }
      val = 0;
      for (int j = i - 1; j >= 0; --j) {
         val -= 1;
         int64_t t = ceil_div (abs (val), A[j]);
 
         while (-t * A[j] > val)
            t -= 1;
 
         val = -t * A[j];
         p += t;
      }
      ans = min (ans, p);
   }
 
   cout << ans << endl;
}