#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;
vector<int> euler;

vector<int> edges[N];
vector<int> d(N, 1);

void dfs(int u, int p) {
  euler.push_back(u);
  for(int v : edges[u]) {
    if(v!=p) {
      d[v] = d[u] + 1;
      dfs(v, u);
    }
  }
  euler.push_back(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    edges[p].push_back(i);
    edges[i].push_back(p);
  }

  dfs(1, -1);
  vector<int> start(n+1,-1);
  vector<int> last(n+1, -1);

  for(int i = 0; i < n+n; ++i) {
    int node = euler[i];
    if(start[node]==-1) {
      start[node] = i;
    } else {
      last[node] = i;
    }
  }

  vector<int> A(n+n);
  for(int i = 1; i <= n; i++) {
    A[start[i]] = d[i];
  }

  vector<vector<int>> depths(n+1);

  for(int i = 0; i < n+n; i++) {
    if(A[i]>0) {
      depths[d[euler[i]]].push_back(i);
    }
  }  

  int q;
  cin >> q;
  while(q--) {
    int U, D;
    cin >> U >> D;

    if(d[U] > D+1) {
      cout << "0\n";
      continue;
    }

    int lo = start[U];
    int hi = last[U];

    vector<int> x = depths[D+1];
    int l_in = upper_bound(x.begin(), x.end(), hi) - x.begin() - 1;
    int f_in = lower_bound(x.begin(), x.end(), lo) - x.begin();
    cout << max(0, l_in-f_in+1) << '\n';
  }
}