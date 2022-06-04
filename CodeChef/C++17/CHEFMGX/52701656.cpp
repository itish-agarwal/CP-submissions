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
const int nax = 1e7 + 2;
bool is_prime[nax];

vector<int> primes;

void test_case() {
  int X, Y;
  cin >> X >> Y;

  if(Y == X + 1) {
    cout << 1 << '\n';
    return;
  }

  int cnt = upper_bound(primes.begin(), primes.end(), Y) - lower_bound(primes.begin(), primes.end(), X + 2);
  cnt = max(cnt, 0);
  cout << Y - X - cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(is_prime, true, sizeof(is_prime));
  for(int p = 2; p < nax; ++p)
    if(is_prime[p])
      for(int j = 2 * p; j < nax; j += p)
        is_prime[j] = false;

  for(int p = 2; p < nax; ++p)
    if(is_prime[p])
      primes.push_back(p);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}