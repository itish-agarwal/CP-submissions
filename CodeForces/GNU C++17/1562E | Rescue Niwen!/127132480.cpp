#include <bits/stdc++.h>
 
using namespace std;
 
template <class T>
struct SparseTable {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;
 
  T merge(const T& a, const T& b) {
    return min(a, b);
  }
 
  SparseTable(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;
 
    const int log = 32 - __builtin_clz(N);
    tab.resize(log);
 
    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }
 
  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};
 
struct SuffixArray {
  string S;
  int N, f0, f1, f2;
  SparseTable<int> *st;
  vector<int> p, c, lcp;
  map<int, int> location;
  //lcp[i] -> value of longest common prefix of two
  //suffixes S[p[i]...N-1] and S[p[i + 1]....N-1];
  
  //TODO: check if default symbol works or change it
  SuffixArray(string s) {
    S = s;
    S += "!";
    f0 = f1 = f2 = 0;
    N = S.size();
    p.resize(N);
    c.resize(N);
    lcp.resize(N);
    location.clear();
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
    f0 = 1;
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
    f1 = 1;
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
  int number_of_different_substrings() {
    build_suffix_array();
    build_lcp_array();
    int ans = 0;
    for(int i = 0; i + 1 < N; i++)
      ans += lcp[i];
    return N*(N - 1)/2 - ans;
  }
 
  //Given two indices i and j in the string, returns the length of
  //longest matching preffix starting from i and j 
  int get_longest_matching_preffix(int i, int j) {
    if(!f0) {
      build_suffix_array();
    }
 
    if(!f1) {
      build_lcp_array();
    }
 
    if(!f2) {
      st = new SparseTable<int> (lcp);
      for(int i = 0; i < (int) p.size(); ++i) 
        location[p[i]] = i;
 
      f2 = 1;
    }
    i = location[i];
    j = location[j];
 
    if(i > j)
      swap(i, j);
 
    --j;
    return st -> query(i, j);
  }
  vector<int> get_suffix_array() {
    return p;
  }
  vector<int> get_lcp_array() {
    return lcp;
  }
};
 
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
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
 
  while(T--) {
    int N;
    cin >> N;
 
    string S;
    cin >> S;
 
    SuffixArray SA(S);
    SA.build_suffix_array();
    SA.build_lcp_array();
 
    vector<int> dp(N);
    for(int i = 0; i < N; ++i)
      dp[i] = N - i;
 
    for(int i = 1; i < N; ++i) {
      for(int j = 0; j < i; ++j) {
        int match = SA.get_longest_matching_preffix(i, j);
        if(match + i < N && S[i + match] > S[j + match]) {
          dp[i] = max(dp[i], dp[j] + N - i - match);
        }
      }
    }
 
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}