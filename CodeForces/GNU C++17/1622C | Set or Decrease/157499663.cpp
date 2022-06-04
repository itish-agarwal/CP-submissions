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
const int64_t INF = (int64_t) 2e17 + 8;
 
int64_t max (int a, int64_t b) {
   if (a >= b)
      return a;
   else
      return b;
}
 
void test_case() {
   int N;
   int64_t K;
   cin >> N >> K;
 
   vector<int64_t> A(N);
   for (auto &a : A)
      cin >> a;
 
   sort(A.begin(), A.end());
 
   int64_t total = accumulate (A.begin(), A.end(), 0LL);
 
   int64_t best =  max(0, total - K);
   int64_t prev = total;
 
   for (int i = N - 1; i >= 1; --i) {
      int64_t rem = prev - A[0] - A[i];
 
      int64_t ab = abs (K - rem);
      int64_t x = ab / (N - i + 1);
      if (rem > K)
         x = -x;
 
      x += 50;
 
      while (rem + x * (N - i + 1) > K)
         x -= 1;
 
      x = min (x, A[0]);
      
      if (x <= A[0]) {
         int64_t pos = A[0] - x + N - i;
         best = min (best, pos);
      }
 
      prev -= A[i];
   }
 
   cout << best << '\n';
}  
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}