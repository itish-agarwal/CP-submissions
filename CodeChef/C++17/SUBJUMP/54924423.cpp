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
   for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
using ll = long long;

//Returns for every index, leftmost index to right of it
//having a value strictly smaller than itself
vector<int> next_smaller(const vector<ll>& values) {
   int n = values.size();
   vector<int> res(n, n);

   stack<ll> pq;
   for(int i = n - 1; i >= 0; --i) {
      while(!pq.empty() && values[i] <= values[pq.top()])
         pq.pop();

      if(!pq.empty())
         res[i] = pq.top();

      pq.push(i);
   }

   return res;
}

void test_case() {
   int N;
   cin >> N;

   vector<ll> A(N);
   for (auto &a : A)
      cin >> a;

   vector<int> ns = next_smaller(A);

   int iter = 0;
   ll ans = 0;

   while (iter < N - 1) {
      if (ns[iter] >= N) {
         ans += (N - iter) * A[iter] - A[N - 1];
         break;
      }  
      else {
         ans += (ns[iter] - iter + 1) * A[iter] - A[ns[iter]];
         iter = ns[iter];
      }
   }

   cout << max(0LL, ans) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}