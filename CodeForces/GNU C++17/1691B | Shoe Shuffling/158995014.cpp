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
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   if (N == 1) {
      cout << -1 << '\n';
      return;
   }
 
   vector<int> result(N);
   iota (result.begin(), result.end(), 1);
 
   for (int i = 0; i < N; ++i) {
      int j = i;
      while (j + 1 < N && A[j+1] == A[i])
         j += 1;
 
      if (j == i) {
         cout << -1 << '\n';
         return;
      }
      
      result[i] = j + 1;
      for (int x = i + 1; x <= j; ++x)
         result[x] = x;
 
      i = j;
   }
 
   print_vector(result);
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}