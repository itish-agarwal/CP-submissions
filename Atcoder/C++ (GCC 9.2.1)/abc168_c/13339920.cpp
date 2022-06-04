#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mp;
const int nax = 1e4;

int main() {

    int a, b, h, m;
    cin >> a >> b >> h >> m;



    double min_an = 6*m;
    double hour_an = 30*h;

    hour_an += (m * 1.0) / 2;

    double theta;
    


    if(hour_an > min_an) {
        theta = min(hour_an - min_an, 360 + min_an - hour_an);
    }else {
        theta = min(min_an - hour_an, 360 + hour_an - min_an);
    }

    double rad = (theta * (3.14159265358979323846)) / 180;

    double ans_sq = a*a*1.0 + b*b*1.0 - 2.0*a*b*cos(rad);


    double ans = pow(ans_sq, 0.5);

    printf("%0.23lf\n", ans);
}