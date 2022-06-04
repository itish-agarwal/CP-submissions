#include <bits/stdc++.h>

using namespace std;
#define int long long

void input(vector<int>& a) {
  string s;
  getline(cin, s);
  vector<int> in{-1};
  for(int i = 0; i < (int)s.size(); i++) {
    if(s[i] == ' ') {
      in.push_back(i);
    }
  }
  in.push_back((int)s.size());
  for(int i = 1; i < (int)in.size(); i++) {
    int L = in[i-1] + 1, R = in[i] - 1;
    if(R >= L) {
      string ss = s.substr(L, R - L + 1);
      int x = stoi(ss);
      a.push_back(x);
    }
  }
}
int waterArea(vector<int> h) {
  int n = h.size();
  vector<int> to_left(n), to_right(n);
  for(int i = 1; i < n; ++i) {
    to_left[i] = max(to_left[i - 1], h[i - 1]);
  }
  for(int i = n-2; i >= 0; --i) {
    to_right[i] = max(to_right[i + 1], h[i + 1]);
  }
  int answer = 0;
  for(int i = 0; i < n; ++i) {
    answer += max(0LL, min(to_left[i], to_right[i]) - h[i]);
  }
  return answer;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a;
  input(a);
  int x = waterArea(a);
  if(x % 2 == 0) {
    cout << x / 2 << " " << x / 2 << '\n';
  } else {
    cout << x / 2 + 1 << " " ;
    double ans = (int)(x/2)*1.0 + 0.5;
    printf("%0.1lf\n", ans);
  }
}
  
