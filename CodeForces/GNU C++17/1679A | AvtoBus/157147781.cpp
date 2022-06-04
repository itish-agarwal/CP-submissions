#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(long long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
 
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
void test_case() {
   int64_t N;
   cin >> N;
 
   if (N % 2 != 0) {
      cout << -1 << '\n';
      return;
   }
 
   int64_t x = (int64_t) 1e18 + 9, y = -1;
 
   for (int64_t four = 0; four <= 100; four++) 
      if (4 * four <= N && (N - 4 * four) % 6 == 0) 
         x = min (x, four + (N - 4 * four) / 6);
      
   for (int64_t six = 0; six <= 100; ++six) 
      if (6 * six <= N && (N - 6 * six) % 4 == 0) 
         y = max (y, six + (N - 6 * six) / 4);
 
   if (y == -1)
      cout << -1 << '\n';
   else
      cout << x << " " << y << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   cin >> tt;
 
   while(tt--)
      test_case();
}