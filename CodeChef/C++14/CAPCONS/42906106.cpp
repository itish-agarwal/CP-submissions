#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long 

bool is_vowel(char ch) {
  if(ch>='A' && ch<='Z') {
    ch += 32;
  }
  return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    for(char& ch : s) {
      if(is_vowel(ch)) {
        if(ch>='A' && ch<='Z') {
          ch += 32;
        }
      } else {
        if(ch>='a' && ch<='z') {
          ch -= 32;
        }
      }
    }
      //if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
      //} else {
        //ch -= 32;
      //}
    //}
    cout << s << '\n';
  }
}
