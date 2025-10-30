#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b; 
        cin >> a >> b;
        if (a==b) cout << 0;
        else if (a%b==0  || b%a==0)
        cout << 1;
        else {
            cout << 2;
        }
        if (t) cout <<'\n';
    }
    return 0;
}
