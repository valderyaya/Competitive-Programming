#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

map<int,int> mp;
int a[5];
signed main(){StarBurstStream
    for(int i=0,x;i<5;++i) cin>>x,mp[x]++;
    if(mp.size()!=2) return cout<<"No",0;
    if(mp.begin()->S==2||mp.begin()->S==3) cout<<"Yes\n";
    else cout<<"No";

}
