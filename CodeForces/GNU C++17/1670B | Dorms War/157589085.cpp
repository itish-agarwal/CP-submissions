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
 
void test_case() {
   int N;
   string S;
   cin >> N >> S;
 
   int k;
   cin >> k;
   set<char> special;
   for (int i = 0; i < k; ++i) {
      char ch;
      cin >> ch;
      special.insert (ch);
   }  
 
   int mx = -1;
   for (int i = 0; i < N; ++i)
      if (special.find (S[i]) != special.end())
         mx = i;
 
   if (mx == -1) {
      cout << 0 << '\n';
      return;
   }
 
   auto ok = [&] (int m) {
      vector<int> covered(N + 1);
 
      for (int i = 0; i < N; ++i)
         if (special.find (S[i]) != special.end()) {
            int l = max(0, i - m), r = i - 1;
            covered[l] += 1;
            covered[r + 1] -= 1;
         }      
 
      for (int i = 1; i <= N; ++i)
         covered[i] += covered[i-1];
 
      for (int i = 0; i < mx; ++i)
         if (!covered[i])
            return false;
 
      return true;
   };
 
   int lo = 0, hi = N + N, ans = 0;
   while (lo <= hi) {
      int m = (lo + hi) / 2;
      if (ok (m)) {
         hi = m - 1;
         ans = m;
      }
      else {
         lo = m + 1;
      }
   }
 
   cout << ans << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}