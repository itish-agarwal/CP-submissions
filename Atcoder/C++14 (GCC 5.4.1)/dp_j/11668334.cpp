#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int n, a[350];
double f[305][305][305];

double fDP(int x, int y, int z, int n){
    
    if(x<0 || y<0 || z<0) {
        return 0;
    }
    if(x==0 && y==0 && z==0){
        return 0;
    }
    if(f[x][y][z] > 0){
        return f[x][y][z];
    }
    int N = x + y + z;
    
    double val = n + x * fDP(x-1,y,z,n) + y * fDP(x+1, y-1, z,n) + z * fDP(x, y+1, z-1, n);
    
    f[x][y][z] = val*(1.0) / N;
    
    return f[x][y][z];
}

/*double f(int x, int y, int z, int n){ //recrusvie
    if(x<0 || y<0 || z<0){
        return 0.0;
    }
    if(x==0 && y==0 && z==0){
        return 0.0;
    } 
    double p0, p1, p2, p3;

    p0 = (n - x - y - z)*(1.0) / n;
    p1 = x * (1.0) / n;
    p2 = y * (1.0) / n;
    p3 = z * (1.0) / n;
    // cout <<p0<<" "<<p1<< " "<<p2 << " "<<p3 << "\n";
    
    return (1+(f(x-1,y,z,n)*p1 + f(x+1,y-1,z,n)*p2 + f(x,y+1,z-1,n)*p3)*(1.0)) / (1 - p0);
 }
*/

int main() {
    int n;
    scanf("%d", &n);
    int x, y, z; x = y = z = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        if(a[i] == 1) x++;
        else if(a[i] == 2) y++;
        else z++;
    }
    // cout << x << " " << y << " " << z << "\n";
    double answer = fDP(x,y,z,n);
    printf("%.10lf\n", answer);
}