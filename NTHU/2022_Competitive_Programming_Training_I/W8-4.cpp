//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

const int z=2e5+5;
int n,k,l,fa[2][z],sz[2][z];
map<pii,int> mp;
int fin(int x,int y){return fa[y][x]==x?x:fa[y][x]=fin(fa[y][x],y);}
void un(int x,int y,int z){
    x=fin(x,z), y=fin(y,z);
    if(x!=y){
        if(sz[z][x]>sz[z][y]) fa[z][y]=x, sz[z][x]+=sz[z][y];
        else fa[z][x]=y, sz[z][y]+=sz[z][x];
    }
}
signed main(){StarBurstStream
    cin>>n>>k>>l;
    for(int i=1;i<=n;++i){
        sz[0][i]=sz[1][i]=1;
        fa[0][i]=fa[1][i]=i;
    }
    for(int x,y;k--;){
        cin>>x>>y;
        un(x,y,0);
    }
    for(int x,y;l--;){
        cin>>x>>y;
        un(x,y,1);
    }
    REP1(i,1,n) mp[mkp(fin(i,0),fin(i,1))]++;
    REP1(i,1,n) cout<<mp[mkp(fin(i,0),fin(i,1))]<<' ';
}
