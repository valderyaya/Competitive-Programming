#include<bits/stdc++.h>
#include"lib1481.h"
using  namespace std;

struct edge{int to,nxt,id;}e[40005];
bitset<2005> vis;
int n,k,h[2005]={},ans=0,cnt=0,out[20005];
void add(int u,int v,int id){
    e[++cnt]=edge{v,h[u],id};
    h[u]=cnt;
}
void dfs(int x){
    vis[x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!out[e[i].id]) out[e[i].id]=++ans;
        if(!vis[v]) dfs(v);
    }
}
int main(){
    Init();
    cin>>n>>k;
    for(int x,y,i=1;i<=k;++i){
        cin>>x>>y;
        add(x,y,i);
        add(y,x,i);
    }
    dfs(1);
    Possible();
    for(int i=1;i<=k;++i) Number(out[i]);
    Finish();
    return 0;
}
