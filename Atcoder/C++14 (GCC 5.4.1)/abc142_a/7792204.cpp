#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  float ans;
  if(n % 2 == 0) {
    ans = 0.50000000000000000000000;
    cout << ans << endl;
  }
  else {
    int odd = n / 2 + 1;
    ans = ((float)odd) / n;
    cout << ans << endl;
  }
}