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
#define ull unsigned long long

int r=1, c[6]={6,6,6,6,6,6};
signed main(){StarBurstStream
    for(int x,y,i=0;i<6;++i){
        cin>>y;
        while(y--) cin>>x, --c[x-1];
    }
    REP(i,6) r*=c[i];
    cout<<r<<"\n";
    return 0;
}
