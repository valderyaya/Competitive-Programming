#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long


int n,q,dep[100005],lca[20][100001];
vector<int> v[100005];
void dfs(int x,int p){
    for(auto &i:v[x]){
        if(i!=p){
            dep[i]=dep[x]+1;
            lca[0][i]=x;
            dfs(i,x);
        }
    }
}
int Lca(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=dep[y]-dep[x], k=0; i; i>>=1, ++k)
        if(i&1) y=lca[k][y];
    if(x==y) return x;
    for(int i=19;~i;--i)
        if(lca[i][x]!=lca[i][y])
            x=lca[i][x], y=lca[i][y];
    return lca[0][x];
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[Lca(x,y)];
}
int main(){Rosario
    cin>>n>>q;
    for(int x,y,i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    lca[0][1]=1;
    dfs(1,1);
    for(int i=1;i<20;++i)
        for(int j=1;j<=n;++j)
            lca[i][j]=lca[i-1][lca[i-1][j]];
    for(int a,b,c,d,x,y;q--;){
        cin>>a>>b>>c>>d;
        x=Lca(a,b), y=Lca(c,d);
        if((dis(y,a)+dis(y,b)==dis(a,b)) || (dis(x,c)+dis(x,d)==dis(c,d))) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}
