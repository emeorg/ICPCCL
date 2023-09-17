#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n; // n: num de nodos, m: num de aristas
 
    int ans = 0;
    
    ans = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        ans = pow(i,2) + pow(i-1,2);
    }
 
    cout << ans;
 
    return 0;
}