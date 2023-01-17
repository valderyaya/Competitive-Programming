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
const int mod=1e9+7;
int n,m,p,a[101][101],ans[101][101];
void mul(){
    int t[101][101]={};
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) (t[i][j]+=a[i][k]*a[k][j]%mod)%=mod;
    REP1(i,1,n) REP1(j,1,n) a[i][j]=t[i][j]; 
}
void mul2(){
    int t[101][101]={};
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) (t[i][j]+=ans[i][k]*a[k][j]%mod)%=mod;
    REP1(i,1,n) REP1(j,1,n) ans[i][j]=t[i][j]; 
}
void power(){
    REP1(i,1,n) ans[i][i]=1LL;
    for(;p;p>>=1,mul()) if(p&1) mul2();
    cout<<ans[1][n]<<"\n";
}
signed main(){StarBurstStream
    cin>>n>>m>>p;
    for(int x,y,i=0;i<m;++i) cin>>x>>y,a[x][y]++;
    power();
}
