#include <bits/stdc++.h>
using namespace std;


int n,m;
vector<int> adj[1001];
bool visisted[1001];


void inp(){
    cin >>n>>m;
    for (int i=0; i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visisted,false,sizeof(visisted));
}

void dfs(int u){
    cout <<u<<" ";
    //danh dau la u da duoc tham
    visisted[u]=true;
    for (int v:adj[u]){
        //Neu dinh v chua duoc tham 
        if (!visisted[v]){
            dfs(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    dfs(1);
    // Your code here
   

    return 0;
}