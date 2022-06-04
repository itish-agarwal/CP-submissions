#include <iostream>
using namespace std;bool prime(int n) {for(int i = 2; i*i <= n; i++){if(n%i == 0){return false;}}return n >= 2;}int main() {int n;cin>>n;n++;while(!prime(n))n++;cout<<n<<'\n';}