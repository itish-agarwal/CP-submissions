#include <bits/stdc++.h>
 
using namespace std;

void test_case() {
  long long n, A, B, k;
  cin >> n >> A >> B >> k;
  long long lcm = (A * B) / __gcd(A, B);
  long long appy = n/A - n/lcm, chef = n/B - n/lcm;
  if(appy + chef >= k) {
    cout << "Win\n";
  } else {
    cout << "Lose\n";
  }
}  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
