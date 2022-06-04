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
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> A(N), B(N);
   for (auto &a : A)
      cin >> a;
 
   for (auto &b : B)
      cin >> b;
 
 
   vector<int> sa = A, sb = B;
   sort (sa.begin(), sa.end());
   sort (sb.begin(), sb.end());
 
   vector<array<int, 2>> ans;
 
   for (int i = 0; i < N; ++i) 
      if (A[i] != sa[i]) {
         bool found = false;
         for (int j = i + 1; j < N; ++j) {
            if (A[j] == sa[i] && B[j] <= B[i]) {
               found = true;
               swap (A[i], A[j]);
               swap (B[i], B[j]);
               ans.push_back ({i, j});
               break;
            }  
         }
 
         if (!found) {
            cout << -1 << '\n';
            return;
         }
      }
 
   for (int i = 0; i < N; ++i)
      if (B[i] != sb[i]) {
         bool found = false;
         for (int j = i + 1; j < N; ++j) {
            if (B[j] == sb[i] && A[j] <= A[i]) {
               found = true;
               swap (A[i], A[j]);
               swap (B[i], B[j]);
               ans.push_back ({i, j});
               break;
            }
         }
 
         if (!found) {
            cout << -1 << '\n';
            return;
         }
      }
 
   // debug(A);
   // debug(B);
 
   cout << ans.size() << '\n';
   for (auto &arr : ans)
      cout << arr[0] + 1 << " " << arr[1] + 1 << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}