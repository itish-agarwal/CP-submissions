#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

struct Mat {
  vector<vector<int>> mat;
  int row, col;
  Mat(int r, int c) {
    row = r;
    col = c;
    mat = vector<vector<int>> (row, vector<int>  (col));
  }
};
Mat multiply(const Mat& a, const Mat& b) {
  Mat ans(a.row, b.col);
  for(int i = 0; i < ans.row; i++) {
    for(int k = 0; k < a.col; k++) {
      if(a.mat[i][k]) {
        for(int j = 0; j < ans.col; j++) {
          ans.mat[i][j] += ((long long)a.mat[i][k] * b.mat[k][j]) % mod;
          ans.mat[i][j] %= mod;
        }
      }
    }
  }
  return ans;
}
Mat raise(const Mat& a, int n) {
  if(n == 0) {
    Mat id(a.row, a.col);
    for(int i = 0; i < a.row; i++) {
      id.mat[i][i] = 1;
    }
    return id;
  }
  Mat half = raise(a, n/2);
  half = multiply(half, half);
  if(n % 2) {
    half = multiply(half, a);
  }
  return half;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Mat use(2, 2);
  use.mat[0][0] = 1;
  use.mat[0][1] = 1;
  use.mat[1][0] = 1;
  int tt;
  cin >> tt;
  while(tt--) {

    int n;
    cin >> n;
    Mat d = use;
    d = raise(d, n);
    cout << d.mat[1][0] << '\n';
  }
}