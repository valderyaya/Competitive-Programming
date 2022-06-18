#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,m,s,lca[20][500005],in[500005],out[500005],dfn;
vector<int> v[500005];
void dfs(int x,int p){
    in[x]=++dfn;
    for(auto &i:v[x]) if(i!=p){
        lca[0][i]=x;
        dfs(i,x);
    }
    out[x]=dfn;
}
bool ac(int x,int y){
    return in[x]<=in[y]&&out[x]>=out[y];
}
int Lca(int a,int b){
    if(ac(a,b)) return a;
    for(int i=19;~i;--i) if(!ac(lca[i][a],b)) a=lca[i][a];
    return lca[0][a];
}
int main(){Rosario
    cin>>n>>m>>s;
    for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    dfs(s,s);
    lca[0][s]=s;
    for(int i=1;i<20;++i) for(int j=1;j<=n;++j) lca[i][j]=lca[i-1][lca[i-1][j]];
    for(int x,y;m--;){
        cin>>x>>y;
        cout<<Lca(x,y)<<"\n";
    }
    return 0;
}
