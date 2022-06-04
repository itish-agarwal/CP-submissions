#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string answer = "";
  //odd length
  for(int i = 0; i < n; ++i) {
    int l = i - 1, r = i + 1;
    while(l>=0 && r<n && s[l]==s[r]) {
      --l;
      ++r;
    }
    ++l;
    --r;
    if(r-l+1 > (int)answer.size()) {
      answer = s.substr(l, r-l+1);
    }
  }
  //even length
  for(int i = 0; i < n-1; ++i) {
    if(s[i] == s[i+1]) {
      int l = i, r = i + 1;
      while(l>=0 && r<n && s[l]==s[r]) {
        --l;
        ++r;
      }
      ++l;
      --r;
      if(r-l+1 > (int)answer.size()) {
        answer = s.substr(l, r-l+1);
      }
    }
  }
  cout << (int) answer.size() << '\n' << answer << '\n';
}
