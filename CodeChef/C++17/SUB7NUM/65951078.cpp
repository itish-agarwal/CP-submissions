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
int N, A[300010], p[8];
int dp[300010][9];

const int mod = 1e9 + 7;
void add_self(int& a, int b) {
   a += b;
   if(a >= mod) {
      a -= mod;
   }
}

int len (int n) {
   int l = 0;
   while (n) {
      n /= 10, l += 1;
   }
   return l;
}

int rec (int i, int r) {
   if (i == N)
      return r == 0;

   if (dp[i][r] > -1)
      return dp[i][r];

   int res = rec (i + 1, r);
   string s = to_string (A[i]);
   int L = s.size();

   int new_r = (r * p[L]) % 7;
   for (int j = 0; j < s.size(); ++j) {
      int d = s[j] - '0';
      int num = d * p[L - j - 1];
      new_r = (new_r + num) % 7;
   }

   add_self (res, rec (i + 1, new_r));
   return dp[i][r] = res;
}

void test_case() {
   cin >> N;

   for (int i = 0; i < N; ++i)
      cin >> A[i];   

   for (int i = 0; i <= N + 1; ++i)
      for (int j = 0; j < 9; ++j)
         dp[i][j] = -1;

   cout << (rec (0, 0) - 1 + mod) % mod << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   p[0] = 1;
   for (int x = 1; x < 8; ++x)
      p[x] = 10 * p[x-1];

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}