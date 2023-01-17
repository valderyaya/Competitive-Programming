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
 
const int z=1e6+5;
int cnt[z],mo[z],f[z];
bitset<z> is;
ll ans;
vector<int> p;
int n;
signed main(){//StarBurstStream
    mo[1]=1;
    for(int i=2;i<=1000000;++i){
        if(!is[i]){
            mo[i]=-1;
            f[i]=i;
            p.em(i);
        }
        for(auto&j:p){
            if(i*j>1000000) break;
            is[i*j]=1;
            f[i*j]=j;
            mo[i*j]=(f[i]==j?0:-mo[i]);
            if(i%j==0) break;
        }
    }
    cin>>n;
    for(int x;n--;){
        cin>>x;
        ++cnt[x];
    }
    for(int i=1;i<=1000000;++i){
        ll x=0;
        for(int j=i;j<=1000000;j+=i) x+=cnt[j];
        ans+=x*(x-1)/2*mo[i];
    }
    cout<<ans<<"\n";
}
