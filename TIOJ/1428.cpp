#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const ll mod=1000000009;
ll dp[150][150]={},n,a[150][150]={},x,y,m,q,k;
void f(){
    ll tmp[150][150]={};
    REP(i,n) REP(j,n) REP(k,n) tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j]%mod)%mod;
     REP(i,n) REP(j,n) a[i][j]=tmp[i][j];
}
void mat(){
    ll tmp[150][150]={};
    REP(i,n) REP(j,n) REP(k,n) tmp[i][j]=(tmp[i][j]+dp[i][k]*a[k][j]%mod)%mod;
    REP(i,n) REP(j,n) dp[i][j]=tmp[i][j];
}
int main(){Rosario
    cin>>n>>m>>q>>k;
    REP(i,n) dp[i][i]=1;
    REP(i,m) cin>>x>>y,a[x][y]++;
    for(;k;k>>=1,f()) if(k&1) mat();
    while(q--) cin>>x>>y,cout<<dp[x][y]<<"\n";
//    system("pause");
    return 0;
}
