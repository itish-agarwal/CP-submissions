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
const int mod = 1e9 + 7;
 
int power (int a, int p) {
   int res = 1;
   while (p > 0) {
      if (p & 1) res = ((int64_t) res * a) % mod;
      p >>= 1; if (p > 0) a = ((int64_t) a * a) % mod;
   }
   return res;
}
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> A(N), B(N), D(N), loc0(N), loc1(N);
 
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
      A[i] -= 1;
      loc0[A[i]] = i;
   }
 
   for (int i = 0; i < N; ++i) {
      cin >> B[i];
      B[i] -= 1;
      loc1[B[i]] = i;
   }
 
   for (auto &d : D)
      cin >> d;
 
   int ans = 1;
 
   vector<bool> vis(N);
   for (int i = 0; i < N; ++i) 
      if (!vis[i]) {
         int cnt = 0, j = i, ok = 1;
         while (!vis[j]) {
            vis[j] = true;
            ok &= D[j] == 0;
            cnt += 1;
            j = loc0[B[j]];
         }
 
         if (ok && cnt > 1)
            ans = ((int64_t) ans * 2) % mod;
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