#include <bits/stdc++.h>

using namespace std;
vector<string> ret;

void f(int i, string s) {
  if(i==3) {
    ret.emplace_back(s);
    return;
  }
  for(char ch = 'a'; ch <= 'c'; ch++) {
    string t = s;
    t.push_back(ch);
    f(i+1, t);
  }
}

int diff(string s, string t) {
  int answer = 0, j = 0;
  for(char ch : s) {
    if(ch==t[j]) {
      j = (j+1) % 3;
    } else {
      answer++;
    }
  }
  return answer;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  if(n <= 3) {
    cout << "0 " << s << '\n';
    return 0;
  }
  int answer = n + n;
  string t;
  for(int i = 0; i < 26; i++) {
    for(int j = 0; j < 26; j++) {
      for(int k = 0; k < 26; k++) {
        string str = "";
        str.push_back(i+'a');
        str.push_back(j+'a');
        str.push_back(k+'a');
        if(diff(s, str) < answer) {
          answer = diff(s, str);
          t = str;
        } else if(diff(s, str) == answer) {
          if(str < t) {
            t = str;
          }
        }
      }
    }
  }
  cout << answer << " ";
  string ans = "";
  n -= answer;
  while(1) {
    if((int)ans.size() + 3 <= n) {
      ans += t;
    } else break;
  }
  ans += t.substr(0, n%3);
  cout << ans << '\n';
  return 0;
}
