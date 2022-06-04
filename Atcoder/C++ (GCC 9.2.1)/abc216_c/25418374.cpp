#include <bits/stdc++.h>

using namespace std;
string operations = "";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long N;
  cin >> N;

  while(N > 0) {
    if(N % 2) {
      operations.push_back('A');
      N -= 1;
    }
    if(N == 0) {
      break;
    }
    operations.push_back('B');
    N /= 2;
  }

  reverse(operations.begin(), operations.end());
  cout << operations << '\n';
}