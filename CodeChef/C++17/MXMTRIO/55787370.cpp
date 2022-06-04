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

int64_t best(vector<int64_t> a) {
   const int n = a.size();
   if (n < 3)
      return -1;

   int64_t res = -1;

   sort(a.begin(), a.end());
   auto update = [&]() {
      res = max(res, (a[0] - a[1]) * a[2]);
   };

   update();
   while(next_permutation(a.begin(), a.end()))
      update();

   return res;
}

void test_case() {
   int N;
   cin >> N;

   vector<int64_t> A(N);
   for (auto &a : A)
      cin >> a;

   int64_t ans = -1;
   sort(A.begin(), A.end());

   for (int b = 0; b <= 3; ++b) {
      vector<int64_t> x;
      for (int i = 0; i < b; ++i)
         x.push_back(A[i]);
      for (int i = N - 1 - b; i < N; ++i)
         if (i > b)
            x.push_back(A[i]);

      ans = max(ans, best(x));
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