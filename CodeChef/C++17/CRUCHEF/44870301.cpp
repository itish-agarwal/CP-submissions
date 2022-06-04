#include <bits/stdc++.h>

using namespace std;

void input(vector<int>& a) {
  string s;
  getline(cin, s);
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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  input(a);
  map<int, int> mp;
  for(auto it : a) mp[it]++;
  vector<int> ff;
  for(auto it : mp) ff.push_back(it.second);
  sort(ff.rbegin(), ff.rend());
  cout << ff[n-1] << '\n';
  return 0;
}