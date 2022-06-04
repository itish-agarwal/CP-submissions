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
   int n, components;
   DSU(int _n) {
      n=  _n;
      p.resize(n);
      r.resize(n);
      components = n;
      iota(p.begin(), p.end(), 0);
   }
   inline int get(int x) { return x == p[x] ? x : p[x] = get(p[x]); }
   
   void unite(int x, int y) {
      x = get(x), y = get(y);
      if(x != y) {
         if(r[y] > r[x]) 
            swap(x, y);
         r[x] += r[x] == r[y];
         components--;
         p[y] = x;
      }
   }
 
   inline bool belong(int x, int y) { return get(x) == get(y); }
   
   vector<vector<int>> get_components () {
      vector<vector<int>> res (n);
      for (int a = 0; a < n; ++a)
         res[get(a)].push_back (a);
 
      return res;
   }
}; 
 
void test_case() {
   int N;
   cin >> N;
 
   DSU d(N);
 
   vector<array<int, 4>> red, blue, total;
   for (int i = 0; i < N; ++i) {
      int c, l, r;
      cin >> c >> l >> r;
 
      total.push_back ({l, r, c, i});
      if (c == 0)
         red.push_back ({l, r, c, i});
      else
         blue.push_back ({l, r, c, i});
   }
 
   sort (red.begin(), red.end());
   sort (blue.begin(), blue.end());
   sort (total.begin(), total.end());
 
   int pr = -1;
 
   for (int i = 0; i < N; ++i) {
      if (total[i][2] == 1) {            
 
         for (int j = pr + 1; j < i; ++j)
            if (total[j][2] == 0 && total[j][1] >= total[i][0])
               d.unite (total[j][3], total[i][3]);
 
         int j = max (i, pr - 1);
 
         while (j + 1 < N && total[j+1][0] <= total[i][1]) {
            j += 1;
            if (total[j][2] == 0)
               d.unite (total[j][3], total[i][3]);
         }
 
         pr = max (pr, j);
      }
   }
 
   pr = -1;
 
   for (auto &arr : total)
      arr[2] ^= 1;
 
   sort (total.begin(), total.end());
 
   for (int i = 0; i < N; ++i) {
      if (total[i][2] == 1) {            
 
         for (int j = pr + 1; j < i; ++j)
            if (total[j][2] == 0 && total[j][1] >= total[i][0])
               d.unite (total[j][3], total[i][3]);
 
         int j = max (i, pr - 1);
 
         while (j + 1 < N && total[j+1][0] <= total[i][1]) {
            j += 1;
            if (total[j][2] == 0)
               d.unite (total[j][3], total[i][3]);
         }
 
         pr = max (pr, j);
      }
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