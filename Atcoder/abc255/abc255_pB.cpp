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

ll n,k;
bitset<1001> sel;
vector<pll> a,b;
double dis(pll x,pll y){
    return sqrt((double)(x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S));
}
signed main(){valder
    cin>>n>>k;
    for(int i=0,x;i<k;++i) cin>>x,sel[x]=1;
    for(int i=1,x,y;i<=n;++i){
        cin>>x>>y;
        if(sel[i]) a.em(x,y);
        else b.em(x,y);
    }
    double mx=0;
    for(auto &i:b){
        double mn=1e9;
        for(auto &j:a)
            mn=min(mn,dis(i,j));
        mx=max(mx,mn);
    }
    cout<<fixed<<setprecision(10)<<mx<<"\n";
}
