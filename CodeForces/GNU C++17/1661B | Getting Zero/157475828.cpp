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
const int mod = 32768;
 
void test_case() {
   int N;
   cin >> N;
 
   for (int i = 0; i < N; ++i) {
      int a;
      cin >> a;
 
      if (a == 0) {
         cout << 0 << " ";
         continue;
      }
 
      int best = mod - a;
      for (int t = 0; t <= 20; ++t) {
         int b = (a + t) % mod;
         if (b == 0) {
            best = min (best, t);
            continue;
         }
 
         int x = t + 15;
         while (b % 2 == 0) {
            b /= 2;
            x -= 1;
         }
 
         best = min (best, x);
      }
 
      cout << best << " ";
   }
 
   cout << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   // cin >> tt;
 
   while(tt--)
      test_case();
}