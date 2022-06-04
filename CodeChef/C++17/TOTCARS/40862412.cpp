
#include <bits/stdc++.h>

using namespace std;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size(), q;
  cin >> q;
  
  vector<vector<int>> cnt(26, vector<int> (n));
  cnt[s[0]-'a'][0] = 1;
  for(int j = 1; j < n; j++) {
    for(int i = 0; i < 26; i++) {
      if(s[j] == i + 'a') {
        cnt[i][j] = cnt[i][j-1] + 1;
      } else {
        cnt[i][j] = cnt[i][j-1];
      }
    }
  }
  
  while(q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int res = 0;
    for(int i = 1; i < 26; i += 2) {
      int count = cnt[i][r] - (l>0 ? cnt[i][l-1] : 0);
      res += (count > 0);
    }
    cout << res << '\n';
  }
  return 0;
}
