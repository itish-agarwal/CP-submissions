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

int lis(const vector<int>& a) {
  vector<int> u;
  for(auto &el : a) {
    auto it = upper_bound(u.begin(), u.end(), el);
    if(it == u.end()) 
      u.push_back(el);

    else 
      *it = el;
  }

  return (int) u.size();
}

void test_case() {
   int N, M;
   cin >> N >> M;

   vector<int> A(N), B(M);

   for (auto &a : A)
      cin >> a;

   for (auto &b : B)
      cin >> b;

   vector<tuple<int, int, int>> els;
   for (int i = 0; i < N; ++i)
      els.push_back(make_tuple(A[i], i, 1));

   for (int i = 0; i < M; ++i)
      els.push_back(make_tuple(B[i], i, 2));

   sort(els.begin(), els.end());

   vector<int> X, Y;
   for (auto [el, in, t] : els)
      if (t == 1) {
         X.push_back(in);
      }  
      else {
         Y.push_back(in);
      }

   cout << lis(X) + lis(Y) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}