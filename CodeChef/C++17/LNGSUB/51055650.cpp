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

struct DSU {
  vector<int> p, r;
  int components;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    components = n;
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
  }
  void unite(int x, int y) {
    x = get(x), y = get(y);
    if(x != y) {
      if(r[y] > r[x]) 
        swap(x, y);
      if(r[x] == r[y])
        r[x]++;
      components--;
      p[y] = x;
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
};

struct SuffixArray {
  string S;
  int N;
  vector<int> p, c, lcp;
  //lcp[i] -> value of longest common prefix of two
  //suffixes S[p[i]...N-1] and S[p[i + 1]....N-1];
  
  //TODO: check if default symbol works or change it
  SuffixArray(string s) {
    S = s;
    S += "!";
    N = S.size();
    p.resize(N);
    c.resize(N);
    lcp.resize(N);
  }

  void counting_sort() {
    //sort array p by values in array c
    vector<int> cnt(N);
    for(auto it : c) 
      cnt[it] += 1;
 
    vector<int> p_new(N);
    //split new array into buckets
    //find index of next element of each bucket
    vector<int> pos(N);
    // pos[i]->first empty element in bucket number i
    for(int i = 1; i < N; i++) {
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for(auto it : p) {
      int bucket = c[it];
      p_new[pos[bucket]] = it;
      pos[bucket] += 1;
    }
    p = p_new;
  }
  void build_suffix_array() {
    //iteration 0
    {
      vector<pair<char, int>> x(N);
      for(int i = 0; i < N; i++)
        x[i] = {S[i], i};
 
      sort(x.begin(), x.end());
 
      for(int i = 0; i < N; i++)
        p[i] = x[i].second;
      c[p[0]] = 0;
      for(int i = 1; i < N; i++) {
        if(x[i].first == x[i - 1].first)
          c[p[i]] = c[p[i - 1]];
        else 
          c[p[i]] = c[p[i - 1]] + 1;
      }
    }
 
    int k = 0;
    while((1 << k) < N) {
      for(int i = 0; i < N; i++) 
        p[i] = (p[i] - (1 << k) + N) % N;
 
      counting_sort();
 
      vector<int> c_new(N);
      c_new[p[0]] = 0;
      for(int i = 1; i < N; i++) {
        pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]};
        pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % N]};
        if(prev == now) 
          c_new[p[i]] = c_new[p[i - 1]];
        else
          c_new[p[i]] = c_new[p[i - 1]] + 1;
      }
      c = c_new;
      k++;
    }
  }

  void build_lcp_array() {
    int k = 0;
    //number of characters that we already know are matching
    for(int i = 0; i + 1 < N; i++) {
      //pi is position of suffix i in suffix array
      //c is already the inverse permutation of p;
      int pi = c[i];
 
      //find previous suffix in suffix array
      int j = p[pi - 1];
 
      //find lcp of suffixes starting from i and j
      while(S[i + k] == S[j + k])
        k++;
 
      lcp[pi - 1] = k;
 
      //get to next suffix
      k = max(0, k - 1);
    }
  }
  long long number_of_different_substrings() {
    build_suffix_array();
    build_lcp_array();
    long long ans = 0;
    for(int i = 0; i + 1 < N; i++)
      ans += lcp[i];
    return (long long)N*(N - 1)/2 - ans;
  }
  vector<int> get_suffix_array() {
    return p;
  }
  vector<int> get_lcp_array() {
    return lcp;
  }
};

void test_case() {
  int N;
  cin >> N;

  vector<string> S(N);
  for (auto &s : S)
    cin >> s;

  string total = "";
  map<int, int> belongs;
  map<pair<int, int>, int> suffix_length;

  for (int i = 0; i < N; ++i) {
    int k = total.size();
    total += S[i] + "#";
    for(int j = k; j < k + S[i].size(); ++j) {
      belongs[j] = i;
      suffix_length[{i, j}] = (int) S[i].size() - (j - k);
    }
  }

  SuffixArray SA(total);
  int n = total.size();

  SA.build_suffix_array();
  SA.build_lcp_array();

  vector<int> p = SA.get_suffix_array();
  vector<int> lcp = SA.get_lcp_array();

  vector<tuple<int, int, int>> edges;

  for(int i = 0; i <= n; ++i) {
    int index0 = p[i];
    int index1 = p[i + 1];
    if(total[index0] != '#' && total[index1] != '#' && belongs[index0] != belongs[index1]) {
      int l0 = lcp[i];
      int l1 = suffix_length[{belongs[index0], index0}];
      int l2 = suffix_length[{belongs[index1], index1}];
      edges.emplace_back(min({l0, l1, l2}), belongs[index0], belongs[index1]);
    }
  }

  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  int ans = 0;

  DSU d(N);
  for (auto [w, a, b] : edges) {
    if(!d.belong(a, b)) {
      d.unite(a, b);
      ans += w;
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