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
const int nax = 1e4 + 7;
int val[nax];

void test_case() {
   int L, R;
   cin >> L >> R;

   map<int, int> ff;
   int mx = -1;

   for (int x = L; x <= R; ++x) {
      int v = val[x];
      ff[v] += 1;

      if (ff[v] > mx) 
         mx = ff[v];
   }

   cout << mx << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   for (int n = 1; n < nax; ++n) {
      int sum = 0, d = 0;
      for (int x = 1; x * x <= n; ++x)
         if (n % x == 0) {
            d += 1;
            sum += x;
            if (x * x != n) 
               sum += n / x, d += 1;
         }

      val[n] = sum / d;
   }

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}