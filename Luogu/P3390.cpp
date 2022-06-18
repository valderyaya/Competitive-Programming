//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

ll a[101][101],n,k,d[101][101];
const ll mod=1e9+7;
void foo(){
    int tmp[101][101]={};
    REP(k,n) REP(i,n) REP(j,n) tmp[i][j]=(tmp[i][j]+a[i][k]*a[k][j])%mod;
    REP(i,n) REP(j,n) a[i][j]=tmp[i][j];
}
void bar(){
    int tmp[101][101]={};
    REP(k,n) REP(i,n) REP(j,n)  tmp[i][j]=(tmp[i][j]+a[i][k]*d[k][j])%mod;
    REP(i,n) REP(j,n) d[i][j]=tmp[i][j];
}
int main(){Rosario
    cin>>n>>k;
    REP(i,n){
        REP(j,n) cin>>a[i][j];
        d[i][i]=1;
    }
    for(;k;k>>=1,foo()) if(k&1) bar();
    REP(i,n){
        REP(j,n) cout<<d[i][j]<<' ';
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
