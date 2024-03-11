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

#define int ll
const int z=2e5+5;
int n,a[z],c[z];
void add(int x,int y){
    for(;x<=n;x+=lb(x)) c[x]=max(c[x],y);
}
int qry(int x){
    int ret=0;
    for(;x;x-=lb(x)) ret=max(ret,c[x]);
    return ret;
}
signed main(){StarBurstStream
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    for(int x,i=1;i<=n;++i){
        cin>>x;
        add(a[i],qry(a[i])+x);
    }
    cout<<qry(n)<<"\n";
}
