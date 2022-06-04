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
   int n;
   string S;
   cin >> n >> S;

   string X = "";
   for (char ch : S)
      if (ch == 'A') {
         X += "BB";
      } else {
         X.push_back(ch);
      }

   const int N = X.size();
   string ans = "";
   int i = 0;

   while (i < N) {
      if (i + 1 < N && X[i] == X[i + 1] && X[i] == 'B') {
         ans.push_back('A');
         i += 2;
      } else {
         ans.push_back(X[i]);
         i += 1;
      }
   }

   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   // cin >> tt;

   while(tt--)
      test_case();
}