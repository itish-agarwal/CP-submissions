
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

vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<int> s;
  int n;
  cin >> n;
  if(n == 0) {
    return 0;
  }
  const int inf = 1e9 + 344;
  int ans[2*n-1][2*n-1];
  for(int i = 0; i < 2*n-1; i++) {
    for(int j = 0; j < 2*n-1; j++) {
      ans[i][j] = inf;
    }
  }
  
  ans[n-1][n-1] = 1;
  
  queue<pair<int, int>> q;
  q.push({n-1, n-1});
  
  while(!q.empty()) {
    
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    
    for(auto can : dir) {
      int xn = x + can.first;
      int yn = y + can.second;
      if(xn>=0 && xn<(2*n-1) && y>=0 && y<(2*n-1)) {
        if(ans[xn][yn] >= inf) {
          ans[xn][yn] = ans[x][y] + 1;
          q.push({xn, yn});
        }
      }
    }
  }
  
  for(int i = 0; i < 2*n-1; i++) {
    for(int j = 0; j < 2*n-1; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
