#include <bits/stdc++.h>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n;
  getline(cin, s);
  vector<vector<string>> ret;
  for(int i = 0; i < n; ++i) {
    getline(cin, s);
    vector<string> a;
    string x = "";
    for(char& ch : s) {
      if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
        x += ch;
      } else {
        if((int) x.size()) {
          a.push_back(x);
        }
        x = "";
      }
    }
    if((int) x.size()) {
      a.push_back(x);
    }
    ret.push_back(a);
  }
  reverse(ret.begin(), ret.end());
  for(auto& it : ret) {
    reverse(it.begin(), it.end());
    for(auto itt : it) {
      cout << itt << " ";
    }
    cout << '\n';
  }
}    
  
