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
        //Khi do thi vo huong 
        adj[y].push_back(x);
        //khi co huong thi bo dong 16
    }
    memset(visisted,false,sizeof(visisted));
}

void bfs(int u){
    //Buoc khoi tao 
    queue<int> q;
    q.push(u);

    cout <<u<<" ";
    //danh dau la u da duoc tham
    visisted[u]=true;
    //Buoc lap 
    while (!q.empty()){
        int v=q.front();// lay dinh o dau hang doi 
        q.pop();
        cout<<v<<" ";
        for (int x :adj[v]){
            if (!visisted[x]){
                q.push(x);
                visisted[x]=true;
            }
        }

    }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inp();
    bfs(1);
    // Your code here
   

    return 0;
}