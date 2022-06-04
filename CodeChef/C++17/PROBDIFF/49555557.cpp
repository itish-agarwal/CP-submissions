#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    map<int, int> freq;
    for(int i = 0; i < 4; ++i) {
      int a;
      cin >> a;
      freq[a]++;
    }
    int n = freq.size();
    if(n == 4 || n == 3) {
      cout << 2 << '\n';
    }
    else if(n == 2) {
      if(freq.begin()->second == 1 || freq.rbegin()->second == 1) {
        cout << 1 << '\n';
      }
      else {
        cout << 2 << '\n';
      }
    }
    else {
      cout << 0 << '\n';
    }
  }
}