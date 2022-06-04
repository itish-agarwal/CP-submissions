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

int moves (string s, string t) {
   const int n = s.size();
   int zo = 0, oz = 0;

   for (int i = 0; i < n; ++i)
      if (s[i] == '0' && t[i] == '1') {
         oz += 1;
      } else if (s[i] == '1' && t[i] == '0') {
         zo += 1;
      }

   return max (oz, zo);
}

void test_case() {
   int N;
   string S;
   cin >> N >> S;

   string S0 = "", S1 = "";
   for (int i = 0; i < N; ++i)
      if (i % 2) {
         S0.push_back('0');
         S1.push_back('1');
      } else {
         S0.push_back('1');
         S1.push_back('0');
      }

   cout << min (moves(S0, S), moves(S1, S)) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}