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
int len (int64_t n) {
   int r = 0;
   while (n > 0) {
      r += 1;
      n /= 10;
   }
 
   return r;
}
 
void test_case() {
   int N;
   int64_t X;
   cin >> N >> X;
 
   map<int64_t, int> dp;
   dp[X] = 0;
 
   queue<int64_t> Q;
   Q.push (X);
 
   map<int, int> already;
   already[len(X)] = 1;
 
   if (len (X) == N) {
      cout << 0 << '\n';
      return;
   }
 
   const int INF = 2e9 + 7;
   int ans = INF;
 
   while (!Q.empty()) {
      int64_t T = Q.front();
      Q.pop();
 
      int64_t t = T;
      while (t > 0) {
         int d = t % 10;
         if (d > 1) {
            int64_t New = T * d;
            
            if (already[len (New)] > 5000) {
               t /= 10;
               continue;
            }
 
            if (dp.count (New) == 0) {
               dp[New] = dp[T] + 1;
               if (len (New) == N) 
                  ans = min (ans, dp[New]);
 
               Q.push (New);
               already[len (New)] += 1;
            }
         }
         t /= 10;
      }
   }
 
   cout << (ans >= INF ? -1 : ans) << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   // cin >> tests;
 
   while(tests--)
      test_case();
}