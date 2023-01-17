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
 
int n,a[1000001],ans=1;
signed main(){StarBurstStream
    cin>>n;
    for(int x,i=0;i<n;++i) cin>>x,++a[x];
    for(int i=2,c=0;i<=1000000;++i,c=0){
        for(int j=i;j<=1000000;j+=i) c+=a[j];
        if(c>1) ans=i;
    }
    cout<<ans<<"\n";
}
