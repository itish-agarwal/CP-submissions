#include <bits/stdc++.h>

using namespace std;
#define int long long 

vector<string> ret;
string s;
int n;

bool is_prime(int n) {
  if(n <= 1) return false;
  if(n == 2) return true;
  for(int i = 2; i*i <= n; ++i) {
    if(n%i == 0) return false;
  }
  return true;
}
bool palprime(string t) {
  string str = t;
  reverse(str.begin(), str.end());
  if(str != t) return false;
  int a = stoll(str);
  return is_prime(a);
}
void rec(int i, string t) {
  if(i == n) {
    if(!t.empty()) {
      sort(t.begin(), t.end());
      if(palprime(t) && t[0]!='0') ret.emplace_back(t);
      while(next_permutation(t.begin(), t.end())) {
        if(palprime(t) && t[0]!='0') {
          ret.emplace_back(t);
        }
      }
    }
    return;
  }
  rec(i + 1, t);
  rec(i + 1, t + s[i]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  s = to_string(n);
  n = s.size();
  rec(0, "");
  set<int> st;
  for(auto it : ret) {
    st.insert(stoll(it));
  }
  if(st.empty()) {
    cout << "-1\n";
    return 0;
  }
  for(auto it = st.begin(); it != st.end(); it++) {
    cout << *it << " ";
  }
  cout << '\n';
}