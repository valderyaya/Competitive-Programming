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

const int maxn=1e9+7;
int n,mx,cmx,mn,cmn,s;
map<double,int> mp;
signed main(){StarBurstStream
    cin>>n;
    for(int x,y,z,i=0;i<n;++i){
        cin>>x>>y>>z;
        if(x) mp[(double)y/x]+=z;
        else mp[maxn]+=z;
    }
    for(auto &i:mp){
        s+=i.S;
        cmx=max(cmx,0)+i.S;
        cmn=min(cmn,0)+i.S;
        mn=min(mn,cmn);
        mx=max(mx,cmx);
    }
    cout<<max(mx,s-mn)<<'\n';
    return 0;
}
