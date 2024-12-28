#include<bits/stdc++.h>
#define N 100100
using namespace std;
int n;
int parent[N][20];
vector<int> adj[N];
int depth[N];

void dfs(int node, int p = 0, int dep){
    parent[node][0] = p;
    depth[node] = dep;

    for(int bit = 1; bit<20; bit++){
        if(parent[node][bit-1]!=-1)
            parent[node][bit] = parent[parent[node][bit-1]][bit-1];
        else{
             parent[node][bit] = -1;
        }
    }
    for(auto it: adj[node]){
        if(p == it) continue;
        dfs(it, node, dep+1);
    }
}

int lca(int u, int v){
    int diff = abs(dep[u]-depth[v]);
    
    if(depth[v]>depth[u]){
        swap(u, v);
    }
    for(int jump=19; jump>=0; jump--){
        if((diff >> jump) & 1){
            u = parent[u][jump];
        }
    }
    
    if(u==v) return u;

    for(int i=19; i>=0; i--){

        if(parent[u][i]!=parent[v][i]){
            u = parent[u][i], v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve(){
    cin>>n;

    for(int i=1; i<n; i++){
        int u;
        cin>>u;
        adj[u].push_back(i+1);
        adj[i+1].push_back(u);
    }  
    for(int i=1; i<=n; i++){
        parent[i][0] = i;
    }
    dfs(1, 0, 0);

    int q;
    cin>>q;

    while(q--){
        int u, v;
        cin>>u>>v;

        cout<<lca(u, v)<<endl;
    }
}

signed main(){

    int t=1; 
    // cin>>t;

    while(t--){
        solve();
    }
}