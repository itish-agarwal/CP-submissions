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
const int INF = 2e9 + 8;

void test_case() {
   int A, B;
   cin >> A >> B;

   int sum = INF;
   int x = -1, y = -1;

   auto update = [&] (int i, int j) {
      if (i + j < sum) {
         sum = i + j;
         x = i, y = j;
      }
   };

   for (int a = A; a <= min (B, A + 5); ++a)
      for (int b = a + 1; b <= min (B, A + 5); ++b) 
         if (__gcd (a, b) > 1)
            update (a, b);

   cout << x << " " << (y == -1 ? "" : to_string(y)) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}