#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    string answer = "";
    while(n--) {
      int dd;
      cin >> dd;
      if(dd % k == 0) {
        answer += '1';
      } else {
        answer += '0';
      }
    }
    cout << answer << '\n';
  }
  return 0;
}
