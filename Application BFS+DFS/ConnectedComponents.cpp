#include <bits/stdc++.h>
using namespace std;


int n,m;
vector<int> adj[10001];
bool visited[1001];
void DFS(int u) {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                DFS(v);
            }
        }
    }

void bfs(int u){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()){
        int v=q.front(); q.pop();
        cout<<v<<" ";
        for (int x: adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

    void connectedComponent(){
        int ans=0;
        memset(visited,false,sizeof(visited));
        for (int i=1; i<=n; i++){
            if (!visited[i]){
                ++ans;
                cout<<"Cac dinh thuoc thanh phan lien thong thu "<<ans<<":\n";
                DFS(i);
                cout<<endl;
            }
        }
        cout<<"So thanh phan lien thong cua do thi :" <<ans<<endl;
        if (ans==1){
            cout <<"Do thi lien thong !\n";
            else cout <<"Do thi khong lien thong !\n";
        }
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Your code here
    cin>>n>>m;
    for (int i=0 ;i<m;i++){
        int x,y; cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connectedComponent();
    return 0;
}