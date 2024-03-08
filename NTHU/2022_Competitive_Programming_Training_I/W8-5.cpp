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

int fa[200001],n,q;
int fin(int x){return fa[x]==x?x:fa[x]=fin(fa[x]);}
signed main(){StarBurstStream
    cin>>n>>q;
    REP1(i,0,n) fa[i]=i;
    for(int x,y;q--;){
        cin>>x>>y;
        x=fin(x-1); y=fin(y);
        if(x^y) fa[x]=y;
    }
    cout<<(fin(0)==fin(n)?"Yes":"No");
}
