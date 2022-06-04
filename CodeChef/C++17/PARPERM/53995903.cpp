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
const int nax = 1e5 + 7;
bool isprime[nax];
vector<int> prs;

template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = int(values.size()) - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << (i < to ? ' ' : '\n');
}
void test_case() {
  int N, K;
  cin >> N >> K;

  int M = min(K, N - K);

  vector<int> st;
  st.push_back(1);

  for(auto &p : prs)
    if(p <= N && 2 * p > N && (int) st.size() < M)
      st.push_back(p);

  vector<int> done(N + 1);
  for(auto &p : st)
    done[p] = 1;

  vector<int> st2;
  for(int a = 1; a <= N; ++a)
    if(!done[a]) 
      st2.push_back(a);

  if((int) st2.size() == K)
    st = st2;

  if((int) st.size() == K) {
    cout << "Yes" << '\n';
    print_vector(st);
    return;
  }

  cout << "No" << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(isprime, true, sizeof(isprime));

  for(int p = 2; p < nax; ++p)
    if(isprime[p])
      for(int j = 2 * p; j < nax; j += p)
        isprime[j] = false;

  for(int p = 2; p < nax; ++p)
    if(isprime[p])
      prs.push_back(p);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}