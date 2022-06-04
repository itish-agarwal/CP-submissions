
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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i==j || i+j==n-1) {
          ans[i][j] = 1;
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(ans[i][j]) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
      cout << '\n';
    }
  }      
  return 0;
}
