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

int n,a[1005],b[1005],ca,cb;
signed main(){valder
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i) if(a[i]==b[i]) ++ca;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(i!=j&&a[i]==b[j]) ++cb;
    cout<<ca<<"\n"<<cb;
}
