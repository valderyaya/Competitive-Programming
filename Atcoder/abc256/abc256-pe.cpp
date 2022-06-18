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
#define mkp make_pair
#define endl "\n"

const int z=200005;
int n,to[z],c[z],in[z];
queue<int> q;
bitset<z> vis;
ll ans;
signed main(){valder
    cin>>n;
    for(int i=1;i<=n;++i) cin>>to[i],++in[to[i]];
    for(int i=1;i<=n;++i) cin>>c[i];
    for(int i=1;i<=n;++i) if(!in[i]) q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        vis[x]=1;
        if(--in[to[x]]==0) q.emplace(to[x]);
    }
    for(int i=1;i<=n;++i)
        if(in[i] && !vis[i]){
            int mn=c[i],x=to[i];
            vis[i]=1;
            while(x!=i){
                vis[x]=1;
                mn=min(mn,c[x]);
                x=to[x];
            }
            ans+=mn;
        }
    cout<<ans;
}
