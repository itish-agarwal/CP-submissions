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
 
struct DSU {
   vector<int> p, r;
   int components;
   DSU(int n) {
      p.resize(n);
      r.resize(n);
      components = n;
      iota(p.begin(), p.end(), 0);
   }
   inline int get(int x) {
      return x == p[x] ? x : p[x] = get(p[x]);
   }
   void unite(int x, int y) {
      x = get(x), y = get(y);
      if(x != y) {
         if(r[y] > r[x]) 
            swap(x, y);
 
         if(r[x] == r[y])
            r[x]++;
         
         components--;
         p[y] = x;
      }
   }
   inline bool belong(int x, int y) {
      return get(x) == get(y);
   }
};
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> P(N);
   for (auto &p : P) {
      cin >> p;
      p--;
   }
 
   DSU d(N);
 
   set<int> S;
   for (auto &p : P) {
      if (S.empty()) {
         S.insert (p);
         continue;
      }
 
      auto x = S.upper_bound (p);
      auto y = S.rbegin();
 
      if (x != S.end() && *x > p)
         d.unite (*x, p);
 
      if (*y > p)
         d.unite (*y, p);
 
      S.insert (p);
   }
 
   S.clear();
   reverse (P.begin(), P.end());
 
   for (auto &p : P) {
      if (S.empty()) {
         S.insert (p);
         continue;
      }
 
      auto x = S.lower_bound (p);
      auto y = S.begin();
 
      if (x != S.end() && *x < p)
         d.unite (*x, p);
 
      if (*y < p)
         d.unite (*y, p);
 
      S.insert (p);
   }
   
   cout << d.components << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}