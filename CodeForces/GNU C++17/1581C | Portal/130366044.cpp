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
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
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
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
 
void test_case() {
  int N, M;
  cin >> N >> M;
 
  vector<vector<char>> grid(N + 1, vector<char> (M + 1));
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j)
      cin >> grid[i][j];
 
  vector<vector<int>> pr(N + 1, vector<int> (M + 1));
  vector<vector<int>> pc(N + 1, vector<int> (M + 1));
  vector<vector<int>> psum(N + 1, vector<int> (M + 1));
 
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j)
      pr[i][j] = pr[i][j-1] + (grid[i][j] == '1');
 
  for(int j = 1; j <= M; ++j)
    for(int i = 1; i <= N; ++i)
      pc[i][j] = pc[i-1][j] + (grid[i][j] == '1');
 
 
  for(int i = 1; i <= N; ++i)
    for(int j = 1; j <= M; ++j)
      psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + (grid[i][j] == '1');
 
  int ans = N * M;
 
  for(int r1 = 1; r1 <= N; ++r1) 
    for(int r2 = r1 + 4; r2 <= N; ++r2) {
      vector<int> cols(M + 1);
      for(int j = M; j >= 1; --j) {
        int val = j - pr[r2][j-1] + j - pr[r1][j-1] - pc[r2-1][j] + pc[r1][j] + psum[r2-1][j-1] - psum[r1][j-1];
        cols[j] = val;
        if(j + 1 <= M) {
          cols[j] = min(cols[j], cols[j + 1]);
        }
      }
      for(int i = 1; i + 3 <= M; ++i) {
        int candidate = -1 - i + pr[r2][i] - 1 - i + pr[r1][i] + r2 - r1 - 1 - pc[r2-1][i] + pc[r1][i] + r2 - r1 - 1 - psum[r2-1][i] + psum[r1][i];
        ans = min(ans, candidate + cols[i + 3]);
      }
    }    
 
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
 
  while(tests--) 
    test_case();
}