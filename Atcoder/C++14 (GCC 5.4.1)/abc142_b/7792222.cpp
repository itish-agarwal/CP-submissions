#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[100000];
  int ans = 0;
  for(int i = 0; i<n; i++) {
    int input;
    cin >> input;
    arr[i] = input;
    if(input >= k) {
      ans ++;
    }
  }
  cout << ans << endl;
}