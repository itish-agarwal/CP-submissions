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
using lli = long long;

void test_case() {
   lli N;
   cin >> N;

   lli ans = -1;
   string S = to_string(N);
   const int n = S.size();

   for (int d = 1; d < n; ++d) {
      if (n % d == 0) {
         lli lo = 0, hi = stoll (S.substr (0, d)), lar = 0;
         while (lo <= hi) {
            lli mid = (lo + hi) >> 1;
            string T = "";
            for (int j = 0; j < n / d; ++j)
               T += to_string (mid);

            lli convert = stoll(T);
            if (convert <= N) {
               lo = mid + 1;
               lar = mid;
            }
            else {
               hi = mid - 1;
            }
         }

         string D = "";
         for (int j = 0; j < n / d; ++j)
            D += to_string (lar);

         lli x = stoll(D);
         ans = max (ans, x);
      }
   }

   lli x = 0;
   for (int j = 0; j < n - 1; ++j)
      x = 10 * x + 9;

   cout << max (ans, x) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}