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

void test_case() {
   long long N, A, B, P, Q, R, S;
   cin >> N >> A >> B >> P >> Q >> R >> S;

   auto black1 = [&](long long k) {
      return max(1 - A, 1 - B) <= k && k <= min(N - A, N - B);
   };

   auto black2 = [&](long long k) {
      return max(1 - A, B - N) <= k && k <= min(N - A, B - 1);
   };

   for(long long i = P; i <= Q; ++i) {
      for(long long j = R; j <= S; ++j) {
         if((i - A == j - B && black1(i - A) && black1(j - B)) || (i - A == B - j && black2(i - A) && black2(B - j)))
            cout << '#';
         else
            cout << '.';
      }
      cout << '\n';
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   // cin >> tests;

   while(tests--)
      test_case();
}