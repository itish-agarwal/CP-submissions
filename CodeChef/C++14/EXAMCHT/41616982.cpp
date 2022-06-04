#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int A, B;
    cin >> A >> B;
    int answer = 0;
    if(A == B) {
      cout << "-1\n";
      continue;
    }
    int d = abs(A - B);
    for(int i = 1; i*i <= d; i++) {
      if(d%i == 0) {
        answer++;
        if(i*i<d) {
          answer++;
        }
      }
    }
    cout << answer << '\n';
  }
  return 0;
}
