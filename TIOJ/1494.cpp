#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const ll md=1e9+7;
ll a,b,g,c[1][2],d[2][2]={{0,1},{1,1}};
void solve(){
    ll t[1][2]={};
    REP(i,1)
        REP(j,2)
            REP(k,2) t[i][j]=(t[i][j]+(c[i][k]*d[k][j])%md)%md;
    REP(i,1) REP(j,2) c[i][j]=t[i][j];
}
void s(){
    ll t[2][2]={};
    REP(i,2) REP(j,2) REP(k,2) t[i][j]=(t[i][j]+(d[i][k]*d[k][j])%md)%md;
    REP(i,2) REP(j,2) d[i][j]=t[i][j];
}
void power(ll n){
    for(;n;n>>=1,s()){
        if(n&1) solve();
    }
}
int main(){//Rosario
    cin>>a>>b;c[0][0]=c[0][1]=1;
    g=__gcd(a+1,b+1)-1;
    power(g-1);
    cout<<c[0][1]<<"\n";
//    system("pause");
    return 0;
}
