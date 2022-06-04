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
 
bool is_perm (vector<int> a, int n) {
   sort (a.begin(), a.end());
   for (int i = 1; i <= n; ++i)
      if (a[i] ^ i)
         return false;
 
   return true;
}
 
void test_case() {
   int N, A, B;
   cin >> N >> A >> B;
 
   vector<int> taken(N + 1);
   vector<int> result(N + 1);
 
   taken[A] = taken[B] = 1;
   result[1] = A;
   result[N/2 + 1] = B;
 
   int itr = N;
   for (int i = 1; i <= N; ++i)
      if (result[i] == 0) {
         while (itr == A || itr == B)
            itr -= 1;
 
         result[i] = itr;
         itr -= 1;
      }
 
   int mn = N * N * N, mx = -1;
   for (int i = 1; i <= N / 2; ++i)
      mn = min (mn, result[i]);
 
   for (int i = N / 2 + 1; i <= N; ++i)
      mx = max (mx, result[i]);
 
   if (mn == A && mx == B && is_perm(result, N))
      for (int i = 1; i <= N; ++i)
         cout << result[i] << " ";
   else
      cout << -1;
 
   cout << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}