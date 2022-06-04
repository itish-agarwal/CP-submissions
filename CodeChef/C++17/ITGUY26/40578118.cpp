
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
const int inf = 1e18 + 424252434;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> fact(10);
  fact[0] = 1;
  for(int i = 1; i < 10; i++) {
    fact[i] = i*fact[i-1];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int sum = 0;
    string s = to_string(n);
    for(char ch : s) {
      sum += fact[ch-'0'];
    }
    if(sum == n) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
