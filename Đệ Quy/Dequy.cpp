#include <bits/stdc++.h>
using namespace std;




int S(int n ){
    if (n==1) return 1;
    else return n +S(n-1);
}

int F(int x ){
    if (x==0 || x==1) return x;
    else return F(x-1) + F(x-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout <<S(4)<<endl;
    cout <<F(4)<<endl;
    return 0;
}
