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
 
int64_t F (string s) {
   int64_t r = 0;
   for (int i = 0; i + 1 < s.size(); ++i) {
      r += 10 * (s[i] - '0') + (s[i+1] - '0');
   }
 
   return r;
}
 
void test_case() {
   int N, K;
   string S;
   cin >> N >> K >> S;
 
   int f = -1, l = -1;
   for (int i = 0; i < N; ++i)
      if (S[i] == '1') {
         if (f == -1)
            f = i;
         
         l = i;
      }
 
   if (f == -1) {
      cout << 0 << '\n';
      return;
   }
 
   if (f == l) {
      int to_end = N - 1 - f;
      if (to_end <= K) {
         cout << 1 << '\n';
         return;
      }
 
      int to_front = f;
      if (to_front <= K) {
         cout << 10 << '\n';
         return;
      }
 
      cout << 11 << '\n';
      return;
   }
 
   int to_end = N - 1 - l, to_front = f;
 
   if (to_end <= K) {
      if (l != N - 1) {
         S.back() = '1';
         S[l] = '0';
         K -= to_end;
      }
   }
 
   if (to_front <= K) {
      if (f != 0) {
         S[0] = '1';
         S[f] = '0';
         K -= to_front;
      }
   }
 
   cout << F(S) << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}