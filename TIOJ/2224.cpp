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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair

#define int ll
const int z=1e5+5;
int n,m,ans,in[z],mn[z];
queue<int> q;
vector<pii> v[z];
signed main(){StarBurstStream
    cin>>n>>m;
    for(int i=2;i<=n;++i) mn[i] = LONG_LONG_MAX;
    for(int x,y,w;m--;){
        cin>>x>>y>>w;
        ++in[y];
        v[x].em(y,w);
    }
    q.emplace(1);
    while(!q.empty()){
        int x=q.front(); q.pop();
        ans+=mn[x];
        for(auto &i:v[x]){
            mn[i.F]=min(mn[i.F],mn[x]+i.S);
            if(--in[i.F]==0) q.emplace(i.F);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
