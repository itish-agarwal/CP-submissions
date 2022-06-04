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

int make (int a, int b, string m) {
   int r = 0;
   for (char ch : m) {
      if (ch == '0' && a == 0)
         break;
      if (ch == '1' && b == 0)
         break;

      a -= ch == '0';
      b -= ch == '1';
      r += 1;
   }

   return r;
}

void test_case() {
   int N;
   string S;
   cin >> N >> S;

   int a = count (S.begin(), S.end(), '0');
   int b = count (S.begin(), S.end(), '1');

   string x = "", y = "";
   for (int i = 0; i < N; ++i)
      if (i % 2) {
         x.push_back('0');
         y.push_back('1');
      } else {
         x.push_back('1');
         y.push_back('0');
      }

   cout << max (make (a, b, x), make (a, b, y)) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;

   while(tt--)
      test_case();
}