#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int k1, k2;
    cin >> k1 >> k2;
    int n = s.size();
    int l = 0, w = 0;
    vector<int> last;
    bool ok = 1;
    int answer = 0;
    for(int i = 0; i < n; i++) {
      if(s[i]=='L') {
        if((i+1)%k1 && (i+1)%k2) {
          last.emplace_back(i);
        }
        l++;
      } else w++;
      if(l >= w) {
        int ul = (int)last.size();
        if(l-ul >= w+ul) {
          ok = 0;
          break;
        }
        int st = 0;
        while(l-st >= w + st) {
          s[last.back()] = 'W';
          last.pop_back();
          answer++;
          st++;
          w++;
          l--;
        }
      }
    }
    if(!ok) {
      cout << "-1\n";
    } else {
      cout << answer << '\n' << s << '\n';
    }
  }
  return 0;
}
