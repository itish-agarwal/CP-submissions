
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

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

vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int m, n, a, d;
    cin >> n >> m >> a >> d;    
    vector<int> ret(5);
    
    ret[0] = a;
    for(int i = 1; i < 5; i++) {
      ret[i] = ret[i-1] + d;
    }
    
    int ans = m-n+1;
    
    for(int mask = 0; mask < 32; mask++) {
      int p = 1;
      int c = __builtin_popcount(mask);
      for(int i = 0; i < 5; i++) {
        if((mask>>i) & 1) {
          p = (p * ret[i]) / __gcd(p, ret[i]);          
        }
      }
      if(c % 2) {
        ans -= (m/p - (n-1)/p);
      } else if(c > 0) {
        ans += (m/p - (n-1)/p);
      }
    }
    
    cout << ans << '\n';
  }
  return 0;
}
      
    
    
    
    
    
    
    
    
    
    
    
    //ret[0] = a;
    //for(int i = 1; i < 5; i++) {
      //ret[i] = ret[i-1] + d;
    //}
  
    ////add all numbers in range l -> r;
    //int ans = m-n+1;
    //cout << ans << endl;
    ////remove numbers div by A....
    //int p = m/ret[0] - (n-1)/ret[0];
    //int q = m/ret[1] - (n-1)/ret[1];
    //int r = m/ret[2] - (n-1)/ret[2];
    //int s = m/ret[3] - (n-1)/ret[3];
    //int t = m/ret[4] - (n-1)/ret[4];
    
    //ans -= (p + q + r + s + t);
    
    //cout << ans << endl;
    
    ////add divisible by any two;
    
    //for(int mask = 0; mask < 32; mask++) {
      //int c = __builtin_popcount(mask);
      //if(c == 2) {
        //int x = -1, y = -1;
        //for(int i = 0; i < 5; i++) {
          //if((mask>>i)&1) {
            //if(x == -1) {
              //x = ret[i];
            //} else {
              //y = ret[i];
            //}
          //}
        //}
        //int g = __gcd(x, y);
        //ans += (m/g - (n-1)/g);
      //}
    //}
    //cout<<ans<<endl;
    
    ////sub div by 3
    //for(int mask = 0; mask < 32; mask++) {
      //int c = __builtin_popcount(mask);
      //if(c == 3) {
        //int x = -1, y = -1, z = -1;
        //for(int i = 0; i < 5; i++) {
          //if((mask>>i)&1) {
            //if(x == -1) {
              //x = ret[i];
            //} else if(y == -1) {
              //y = ret[i];
            //} else {
              //z = ret[i];
            //}
          //}
        //}
        //int g = __gcd(x, __gcd(y, z));
        //ans -= (m/g - (n-1)/g);
      //}
    //}
    //cout << ans << endl;
    ////add div by 4
    //for(int mask = 0; mask < 32; mask++) {
      //int c = __builtin_popcount(mask);
      //if(c == 4) {
        //int x = -1, y = -1, z = -1, t = -1;
        //for(int i = 0; i < 5; i++) {
          //if((mask>>i)&1) {
            //if(x == -1) {
              //x = ret[i];
            //} else if(y == -1) {
              //y = ret[i]; 
            //} else if(z == -1) {
              //z = ret[i];
            //} else {
              //t = ret[i];
            //}
          //}
        //}
        //int g = __gcd(x, __gcd(y, __gcd(z, t)));
        //ans += (m/g - (n-1)/g);
      //}
    //}
    //cout << ans << endl;
    //int g = 0;
    //for(int x : ret) {
      //g = __gcd(g, x);
    //}
    //ans -= (m/g - (n-1)/g);
    //cout << ans << '\n';
  //}
  //return 0;
//}
    
  
      
  
  
