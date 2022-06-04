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
 
template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
   for (T v : values) 
      cout << v << " ";
 
   return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
   if(from < 0) from = 0;
   if(to < 0) to = int(values.size()) - 1;
 
   for(int i = from; i <= to; ++i) 
      cout << values[i] << (i < to ? ' ' : '\n');
}
 
bool check (vector<int> a) {
   const int n = a.size();
   for (int i = 0; i < n; ++i) {
      int x = a[(i+1) % n];
      int y = a[(i-1+n) % n];
      if (a[i] > max (x, y))
         continue;
      if (a[i] < min (x, y))
         continue;
 
      return false;
   }
 
   return true;
}
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   sort (A.begin(), A.end());
 
   vector<int> order(N);
 
   int k = 0;
   for (int i = 0; 2 * i < N; i++) {
      order[2 * i] = A[i];
      k += 1;
   }
 
   multiset <int> S;
   for (int i = k; i < N; ++i)
      S.insert (A[i]);
 
   int it = (N % 2 == 0 ? N - 1 : N - 2);
 
   while (!S.empty()) {
      int x = order[(it-1+N) % N];
      int y = order[(it+1) % N];
 
      auto itt = S.upper_bound (max (x, y));
      if (itt == S.end()) {
         cout << "NO" << '\n';
         return;
      }
 
      order[it] = *itt;
      S.erase (S.find (*itt));
 
      it = (it - 2 + N) % N;
   }
 
   cout << (check (order) ? "YES" : "NO") << '\n';
   if (check (order))
      print_vector(order);
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}