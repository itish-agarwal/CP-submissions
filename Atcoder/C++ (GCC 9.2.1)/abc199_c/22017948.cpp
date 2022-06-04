#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  n += n;
  string s;
  cin >> s;

  int cnt = 0;
  string l = s.substr(0, n/2);
  string r = s.substr(n/2);

  int qq;
  cin >> qq;
  while(qq--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
    --b;
    int left = min(a, b), right = max(a, b);
    // cout << left << " " << right << endl;
    if(t == 1) {
      if(cnt % 2) {
        //r comes before
        if(left < n/2) {
          if(right < n/2) {
            char ch = r[left];
            r[left] = r[right];
            r[right] = ch;
            // swap(r[left], r[right]);
          } else {
            // swap(r[left], l[right - n/2]);
            char ch = r[left];
            r[left] = l[right - n/2];
            l[right - n/2] = ch;
          }
        } else {
          // swap(l[left], l[right]);
          left -= n/2;
          right -= n/2;
          char ch = l[left];
          l[left] = l[right];
          l[right] = ch;
        }
      } else {
        if(left < n/2) {
          if(right < n/2) {
            // swap(l[left], l[right]);
            char ch = l[left];
            l[left] = l[right];
            l[right] = ch;
          } else {
            // swap(l[left], r[right - n/2]);
            char ch = l[left];
            l[left] = r[right - n/2];
            r[right - n/2] = ch;
          }
        } else {
          // swap(r[left], r[right]);
          left -= n/2;
          right -= n/2;
          char ch = r[left];
          r[left] = r[right];
          r[right] = ch;
        }
      }
    } else {
      cnt++;
    }
  }
  if(cnt % 2) {
    cout << r + l << '\n';
  } else {
    cout << l + r << '\n';
  }
}