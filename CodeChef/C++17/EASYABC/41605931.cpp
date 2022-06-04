#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int fa = -1, la = -11, fb = -1, lb = -1, fc = -1, lc = -1;
  for(int i = 0; i < n; i++) {
    if(s[i]=='a') {
      if(fa<=-1) {
        fa = i;
      }
      la = i;
    } else if(s[i]=='b') {
      if(fb<=-1) {
        fb = i;
      } 
      lb = i;
    } else {
      if(fc<=-1) {
        fc = i;
      }
      lc = i;
    }
  }
  int answer = 0;
  if(fa>-1) {
    if(fb>-1) {
      answer = max(answer, max(abs(fa-fb), abs(fa-lb)));
      answer = max(answer, max(abs(la-fb), abs(la-lb)));
    }
    if(fc>-1) {
      answer = max(answer, max(abs(fa-fc), abs(fa-lc)));
      answer = max(answer, max(abs(la-fc), abs(la-lc)));
    }
  }
  if(fb>-1) {
    if(fa>-1) {
      answer = max(answer, max(abs(fb-fa), abs(fb-la)));
      answer = max(answer, max(abs(lb-fa), abs(lb-la)));
    } 
    if(fc>-1) {
      answer = max(answer, max(abs(fb-fc), abs(fb-lc)));
      answer = max(answer, max(abs(lb-fc), abs(lb-lc)));
    }
  }
  if(fc>-1) {
    if(fa>-1) {
      answer = max(answer, max(abs(fc-fa), abs(fc-la)));
      answer = max(answer, max(abs(lc-fa), abs(lc-la)));
    }
    if(fb>-1) {
      answer = max(answer, max(abs(fc-fb), abs(fc-lb)));
      answer = max(answer, max(abs(lc-fb), abs(lc-lb)));
    }
  }
  cout << answer << '\n';
  return 0;
}
    
     
