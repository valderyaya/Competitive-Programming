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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

const ll mod=1000000007;
ll n,m,a,b,x[1][2],y[2][2],t;
void mul1(){
    ll tmp[2][2]={};
    REP(i,2)
        REP(j,2)
            REP(k,2) tmp[i][j]=(tmp[i][j]+y[i][k]*y[k][j])%mod;
    REP(i,2) REP(j,2) y[i][j]=tmp[i][j];
}
void mul2(){
    ll tmp[1][2]={};
    REP(i,1)
        REP(j,2)
            REP(k,2) tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j])%mod;
    REP(i,1) REP(j,2) x[i][j]=tmp[i][j];
}
void power(ll n){
    for(;n;n>>=1,mul1()){
        if(n&1) mul2();
    }
}
int main(){Rosario
    cin>>n>>m>>a>>b>>t;
    y[0][0]=0,y[0][1]=a,y[1][0]=1,y[1][1]=b;
    x[0][0]=n,x[0][1]=m;
    power(t-1);
    cout<<x[0][0]<<"\n";
//    system("pause");
    return 0;
}
