#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; vector<int> arrayn(n);

    for (int i = 0; i < n; ++i) {
        cin >> arrayn[i];
    }

    int c; cin >> c; vector<int> arrayc(c);

    for (int i = 0; i < c; ++i) {
        cin >> arrayc[i];
    }

    sort(arrayn.begin(), arrayn.end());

    for (int i = 0; i < c; ++i) {
        int contador = upper_bound(arrayn.begin(), arrayn.end(), arrayc[i]) - arrayn.begin();
        cout << contador << endl;
    }

    return 0;
}