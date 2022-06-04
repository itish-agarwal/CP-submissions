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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int inf = 2e9 + 5555;
  vector<vector<int>> dp(n, vector<int> (m, inf));
  
  set<int> s;
  int con = b.back();
  for(int i = n-1; i >= 0; i--) {
    s.insert(a[i]);
    if(s.find(con) == s.end()) {
      dp[i][m-1] = n-i;
    } else {
      dp[i][m-1] = n-i-1;
    }
  }
  s.clear();
  con = a.back();
  for(int j = m-1; j >= 0; j--) {
    s.insert(b[j]);
    if(s.find(con) == s.end()) {
      dp[n-1][j] = m-j;
    } else {
      dp[n-1][j] = m-j-1;
    }
  }
  for(int i = n-2; i >= 0; i--) {
    for(int j = m-2; j >= 0; j--) {
      dp[i][j] = dp[i+1][j+1] + (a[i] != b[j]);
      dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
      //dp[i][j] = min(dp[i][j], 1 + dp[i][j+1);
      dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
      dp[i][j] = min(dp[i][j], 2 + dp[i+1][j+1]);
    }
  }
  //for(int i = 0; i < n; i++) {
    //for(int j = 0; j < m; j++ ){
      //cout << dp[i][j] << " ";
    //}cout<<endl;
  //}
  cout << dp[0][0] << '\n';
  return 0;
}
  
  
