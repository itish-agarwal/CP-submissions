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

vector<pair<int64_t, int>> factors (int64_t n) {
   int64_t nn = n;
   vector<pair<int64_t, int>> result;

   for (int64_t x = 2; x * x <= nn; ++x) {
      if (n % x == 0) {
         int t = 0;
         while (n % x == 0) 
            n /= x, t += 1;

         result.emplace_back (x, t);
      }
   }

   if (n > 1)
      result.emplace_back (n, 1);

   return result;
}

void test_case() {
   int64_t X;
   int C;
   cin >> X >> C;

   vector<pair<int64_t, int>> ff = factors (X);

   for (auto &[pr, tt] : ff) {
      tt %= C;
      if (2 * tt > C)
         tt = C - tt;
   }

   int64_t res = 1;

   for (auto [pr, tt] : ff)
      for (int j = 0; j < tt; ++j)
         res *= pr;
   
   cout << res << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}