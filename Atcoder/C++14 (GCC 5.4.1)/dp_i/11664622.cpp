#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    
    vector<double> f(n + 1);
    f[0] = 1;
    //f[i] stores the answer for i heads in total n tosses
    for(int i = 1; i<=n; i++){
        double p;
        scanf("%lf", &p);
        
        for(int j = i; j >= 0; j--){
            f[j] = (i == 0 ? 0 : f[j-1] * p) + f[j] * (1 - p);
        }
    }
    
    double ans = 0;
    for(int h = 0; h<=n; h++){
        if(2*h > n){
            ans += f[h];
        }
    }
    
    printf("%.10lf\n", ans);
}