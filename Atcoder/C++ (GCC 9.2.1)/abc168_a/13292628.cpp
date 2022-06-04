#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mp;
const int nax = 1e4;

int main() {
    int n;
    cin >> n;
    int dig = n%10;

    if(dig==3) {
        cout << "bon\n";
    }else if(dig==0 || dig==1 || dig==6 || dig==8) {
        cout << "pon\n";
    }else {
        cout << "hon\n";
    }
    return 0;
}