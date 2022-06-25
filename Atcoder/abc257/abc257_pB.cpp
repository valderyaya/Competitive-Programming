#pragma GCC optimize("O2")
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

int n,k,q,a[205];
bitset<205> vis;
signed main(){valder
    cin>>n>>k>>q;
    for(int i=1;i<=k;++i) cin>>a[i],vis[a[i]]=1;
    for(int x,i=0;i<q;++i){
        cin>>x;
        if(a[x]<n&&!vis[a[x]+1]){
            vis[a[x]]=0;
            vis[++a[x]]=1;
        }
    }
    for(int i=1;i<=k;++i) cout<<a[i]<<' ';
}
