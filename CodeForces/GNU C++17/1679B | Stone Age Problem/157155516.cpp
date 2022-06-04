#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(long long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
 
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
void test_case() {
   int N, Q;
   cin >> N >> Q;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   vector<int> last_chaneg(N, -1);
   int64_t sum = accumulate (A.begin(), A.end(), 0LL);
   int pr = -1, last = -1;
 
   for (int q = 0; q < Q; ++q) {
      int t;
      cin >> t;
      if (t == 1) {
         int i, x;
         cin >> i >> x; 
         i -= 1;
 
         if (last > last_chaneg[i]) {
            last_chaneg[i] = q;
            A[i] = pr;
         }
 
         sum -= A[i];
         A[i] = x;
         sum += x;
      }
      else {
         int x;
         cin >> x;
 
         pr = x;
         last = q;
         sum = (int64_t) x * N;
      }
 
      cout << sum << '\n';
   }
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   // cin >> tt;
 
   while(tt--)
      test_case();
}