#include <bits/stdc++.h>
 
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size();
  for(int i = 0; i < min(n, m); ++i) {
    if(a[i] < b[i]) {
      return 1;
    } else if(b[i] < a[i]) {
      return 0;
    }
  }
  return (int) a.size() < (int) b.size();
}  
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> a;
  int n, x;
  cin >> n;
  while(n--) {
    vector<int> b;
    while(1) {
      cin >> x;
      if(x == -1) break;
      b.push_back(x);
    }
    a.push_back(b);
  }
  sort(a.begin(), a.end(), cmp);
  for(auto v : a) {
    for(auto it : v) {
      cout << it << " " ;
    }
    cout << '\n';
  }
}
