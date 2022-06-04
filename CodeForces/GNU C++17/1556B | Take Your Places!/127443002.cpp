#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(long double a) { cout << a; }
void pr(long long a) { cout << a; }
void pr(double a) { cout << a; }
void pr(string a) { cout << a; }
void pr(float a) { cout << a; }
void pr(char a) { cout << a; }
void pr(long a) { cout << a; }
void pr(bool a) { cout << a; }
void pr(int a) { cout << a; }
 
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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<int> values;
  for(auto value : pq) 
    values.push_back(value);
 
  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  int n = v.size();
 
  for(int i = 0; i < n; ++i) {
    pr(v[i]); cout << (i + 1 < n ? " " : "");
  }
}
template <class T> void pr(const set<int> pq) {
  vector<int> values;
  for(auto value : pq)
    values.push_back(value);
 
  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t);
  if(sizeof...(v))
    cout << ", ";
 
  pr(v...);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests;
  cin >> tests;
 
  while(tests--) {
    int N;
    cin >> N;
 
    vector<int> A(N);
    for(auto& a : A) {
      cin >> a;
      a %= 2;
    }
 
    int sum = accumulate(A.begin(), A.end(), 0), odds = sum;
    sum = max(sum, N - sum);
 
    if(sum > (N + 1) / 2) {
      cout << -1 << '\n';
    }
 
    else {
 
      auto calculate = [&](int odd_index, int even_index) {
        long long res = 0;
        for(int i = 0; i < N; ++i) {
          if(A[i] % 2) {
            res += max(0, i - odd_index);
            odd_index += 2;
          }
 
          else {
            res += max(0, i - even_index);
            even_index += 2;
          }
        }
        return res;
      };
 
      long long ans;
 
      if(N % 2) {
        if(odds > N - odds) {
          ans = calculate(0, 1);
        }
        else {
          ans = calculate(1, 0);
        }
      }
 
      else {
        ans = min(calculate(0, 1), calculate(1, 0));
      }
      cout << ans << '\n';
    }
  }
}