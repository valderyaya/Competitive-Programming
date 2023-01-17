#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
 
const int z=1e5+5;
int pa[z],n,m,cnt,sz[z],mx;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
signed main(){valder
    cin>>n>>m; cnt=n; mx=1;
    REP1(i,1,n) pa[i]=i,sz[i]=1;
    for(int x,y,px,py;m--;){
        cin>>x>>y;
        px=fin(x),py=fin(y);
        if(px!=py){
            --cnt;
            if(sz[px]>sz[py]) pa[py]=px, sz[px]+=sz[py];
            else pa[px]=py, sz[py]+=sz[px];
            mx=max({mx,sz[px],sz[py]});
        }
        cout<<cnt<<' '<<mx<<"\n";
    }
 
}
