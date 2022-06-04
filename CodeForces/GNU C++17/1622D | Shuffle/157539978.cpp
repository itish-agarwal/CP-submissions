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
 
const int nax = 3e5 + 7;
const int mod = 998244353;
vector<int> fact, inv_fact; //call init()
 
void add_self(int& a, int b) {
   a += b;
   if(a >= mod) a -= mod;
}
 
int power (int a, int p) {
   int res = 1;
   while (p > 0) {
      if (p & 1) res = ((int64_t) res * a) % mod;
      p >>= 1; if (p > 0) a = ((int64_t) a * a) % mod;
   }
   return res;
}
 
int factorial (int n) { return fact[n]; }
int inv_modulo (int n) { return power (n, mod - 2); }
int inv_factorial (int n) { return inv_fact[n]; }
 
int C (int n, int r) {
   if (r < 0 || r > n) return 0; 
   int ans = factorial (n);
   int den = ((int64_t) inv_factorial (r) * inv_factorial (n - r)) % mod;
   return (int64_t) ans * den % mod;
}
 
int permute (int n, int r) {
   if (r < 0 || r > n) return 0;
   int ans = factorial (n);
   return (int64_t) ans * inv_factorial (n - r) % mod;
}
 
void init () {
   fact.assign (nax, 1);
   inv_fact.resize (nax);
 
   for (int i = 2; i < nax; ++i)
      fact[i] = (int64_t) i * fact[i-1] % mod;
 
   inv_fact.back() = inv_modulo (factorial (nax - 1));
   for (int i = nax - 2; i >= 0; --i)
      inv_fact[i] = (int64_t) (i + 1) * inv_fact[i + 1] % mod;
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   init(); 
 
   int N, K;
   string S;
   cin >> N >> K >> S;
   vector<int> a(N);
   for (int i = 0; i < N; ++i)
      a[i] = S[i] - '0';
 
   int ans = 1;
   vector<int> pref (N + 1);
   for (int i = 1; i <= N; ++i)
      pref[i] = pref[i-1] + a[i-1];
 
   if (pref[N] >= K) {
      for (int i = 0; i < N; ++i)
         for (int j = i + 1; j < N; ++j) {
            int cnt = pref[j + 1] - pref[i];
            if (cnt <= K) {
               cnt -= (a[i] ^ 1) + (a[j] ^ 1);
               add_self (ans, C (j - i - 1, cnt));
            }
         }
   }
 
   cout << ans << '\n';
}