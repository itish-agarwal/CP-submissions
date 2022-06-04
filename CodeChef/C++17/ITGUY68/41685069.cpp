#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int sp = n/2;
    int len = n/2 - 1;
    int st = n/2 + 1;
    for(int i = 0; i < n/2; i++) {
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      sp--;
      for(int j = 0; j < len; j++) {
        cout << st + j;
      }
      st--;
      cout << '\n';
    }
    for(int i = 0; i < len; i++) {
      cout << i + 1;
    }
    cout << '\n';
    st++;
    sp++;
    for(int i = 0; i < n/2; i++) {
      for(int j = 0; j < sp; j++) {
        cout << " ";
      }
      sp++;
      for(int j = 0; j < len; j++) {
        cout << st + j;
      }
      st++;
      cout << '\n';
    }
  }
  return 0;
}

