
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}

//ABCDEFGHIJKLMNOPQRSTUVWXYZ

vector<int> add{98, 57, 31, 45, 46};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int n = s.length();
  vector<int> in{-1};
  for(int i = 0; i < n; i++) {
    if(s[i] == ' ') {
      in.push_back(i);
    }
  }
  in.push_back(n);
  vector<string> they;
  int len = 1e18; 
  string t = "";
  for(int i = 1; i < (int)in.size(); i++) {
    int st = in[i-1] + 1;
    int en = in[i] - 1;
    string str = s.substr(st, en-st+1);
    if(!str.empty()) {
      they.push_back(str);
      if((int)str.size() < len) {
        len = (int)str.size();
        t = str;
      }
    }
  }
  cout << t << " ";
  for(string str : they) {
    cout << str << " " << t << " ";
  }
  cout << '\n';
  return 0;
}
