#include <bits/stdc++.h>

using namespace std;

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

//////
vector<string> trim(vector<string> shape) {
  int n = shape.size(), m = shape[0].size();

  int a = -1, b = -1, c = n, d = m;

  for(int i = 0; i < n; ++i) {
    int sum = 0;
    for(int j = 0; j < m; ++j) {
      sum += shape[i][j] == '#';
    }
    if(sum == 0) {
      a += 1;
    }
    else {
      break;
    }
  }

  for(int j = 0; j < m; ++j) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      sum += shape[i][j] == '#';
    }
    if(sum == 0) {
      b += 1;
    }
    else {
      break;
    }
  }

  for(int i = n - 1; i >= 0; --i) {
    int sum = 0;
    for(int j = 0; j < m; ++j) {
      sum += shape[i][j] == '#';
    }
    if(sum == 0) {
      c -= 1;
    }
    else {
      break;
    }
  }

  for(int j = m - 1; j >= 0; --j) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      sum += shape[i][j] == '#';
    }
    if(sum == 0) {
      d -= 1;
    }
    else {
      break;
    }
  }

  vector<string> res;
  for(int i = a + 1; i < c; ++i) {
    string row = "";
    for(int j = b + 1; j < d; ++j) {
      row.push_back(shape[i][j]);
    }
    res.push_back(row);
  }

  return res;
}

vector<string> rotate(vector<string> shape) {
  int n = shape.size(), m = shape[0].size();

  vector<string> res;
  for(int j = 0; j < m; ++j) {
    string row = "";
    for(int i = n - 1; i >= 0; --i) {
      row.push_back(shape[i][j]);
    }
    res.push_back(row);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<string> S(N), T(N);

  for(int i = 0; i < N; ++i)
    cin >> S[i];

  for(int i = 0; i < N; ++i)
    cin >> T[i];

  S = trim(S);
  T = trim(T);

  for(int rep = 0; rep < 6; ++rep) {
    S = rotate(S);
    for(int k = 0; k < 6; ++k) {
      T = rotate(T);
      if(S == T) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }

  cout << "No" << '\n';
}