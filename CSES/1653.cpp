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
int f[1049000],w[1049000],n,m,a[21];
const int inf=1e9;
signed main(){StarBurstStream
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    f[0]=1;
    for(int i=1;i<(1<<n);++i){
        f[i]=w[i]=inf;
        for(int j=0;j<n;++j)
            if(i>>j&1){
                int k=i^(1<<j);
                if(w[k]+a[j]<=m){
                    if(f[k]<f[i] || (f[k]==f[i]&&w[k]+a[j]<w[i])) {
                        f[i]=f[k];
                        w[i]=w[k]+a[j];
                    }
                }else{
                    if(f[k]+1<f[i]||(f[k]+1==f[i]&&a[j]<w[i])){
                        f[i]=f[k]+1;
                        w[i]=a[j];
                    }
                }
            }
    }
    cout<<f[(1<<n)-1]<<"\n";
}
