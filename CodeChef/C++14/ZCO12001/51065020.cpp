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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

//dp[i] is length of longest balanced parenthesis ending at index i
vector<int> func(string S) {
  int N = S.size();

  vector<int> dp(N);
  for(int i = 1; i < N; ++i) {
    if(S[i] == ')') {
      if(S[i-1] == '(') {
        dp[i] = 2 + (i - 2 >= 0 ? dp[i-2] : 0);
      }

      else {
        int l = dp[i-1];
        if(i -l-1 >= 0 && S[i-l-1] == '(') {
          dp[i] = dp[i-1] + 2 + (i-l-2 >= 0 ? dp[i-l-2] : 0);
        }
      }
    }
  }

  return dp;
}
void test_case() {
  int N;
  cin >> N;

  string S = "";
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    S.push_back((a == 2 ? ')' : '('));
  }

  vector<int> dp = func(S);
  int max_nest = -1, in0 = -1, max_balanced = -1, in1 = -1;
  int diff = 0;

  for(int i = 0; i < N; ++i) {
    diff += (S[i] == '(' ? +1 : -1);
    if(diff > max_nest) {
      max_nest = diff;
      in0 = i;
    }

    if(S[i] == ')' && i > 0) {
      int len = dp[i-1];
      if(i-len-1 >= 0 && S[i-len-1] == '(') {
        if(len > max_balanced) {
          max_balanced = len;
          in1 = i - len - 1;
        }
      }
    }
  }

  cout << max_nest << " " << in0 + 1 << " " << max_balanced + 2 << " " << in1 + 1 << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}