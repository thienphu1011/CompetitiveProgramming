#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
const int maxn= 10001;
int n,m,s,t;
vector<pair<int,int>> adj[maxn];
int pre[maxn];
void inp(){
    cin >>n >>m>>s>>t;
    for (int i=0; i<m; i++){
        int x,y,w; cin >> x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}
const int INF=1e9;

void dijkstra(int s, int t){
    //Mang luu khoang cach duong di 
    vector<ll> d(n+1, INF);
    d[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>Q;
    //{khoang cach , dinh}
    Q.push({0,s});
    while (!Q.empty()){
        //Chon ra dinh co khoang cach tu s nho nhat 
        pair<int,int> top=Q.top(); Q.pop();
        int u=top.second;
        int kc=top.first;
        if(kc>d[u]) continue;
        //Relaxation : Cập nhập khoảng cách từ s cho tới mọi đỉnh kề u
        for (auto it :adj[u]){
            int v=it.first;
            int w=it.second;
            if (d[u]>d[u]+w){
            d[v]=d[u]+w;
            Q.push({d[u],v});
            pre[v]=u;// truoc v la u
        }

    }
}

cout <<d[t]<<endl;
vector<int>path;
while (1){
    path.push_back(t);
    if (t==s) break;
    t=pre[t];
}
reverse(begin(path),end(path));
for (int x:path){
    cout <<x<<" ";
}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Your code here
    inp();
    dijkstra(s,t);

    return 0;
}