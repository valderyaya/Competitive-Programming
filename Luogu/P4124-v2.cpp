//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll f[11][11][11][2][2][2][2];
int a[12],id;
ll dfs(int pos,int pv,int ppv,bool ck,bool lmt,bool _4,bool _8){
    if(_4&&_8) return 0;
    if(pos<1) return ck;
    if(~f[pos][pv][ppv][ck][lmt][_4][_8]) return f[pos][pv][ppv][ck][lmt][_4][_8];
    ll res=0,up=lmt?a[pos]:9;
    REP1(i,0,up)
        res+=dfs(pos-1,i,pv,ck||(i==pv&&i==ppv),lmt&&(i==up),_4||(i==4),_8||(i==8));
    return f[pos][pv][ppv][ck][lmt][_4][_8]=res;
}
ll cal(ll x){
    if(x<1e10) return 0;
    for(id=0;x;x/=10) a[++id]=x%10;
    memset(f,-1,sizeof(f));
    ll res=0;
    REP1(i,1,a[id]) res+=dfs(10,i,0,0,i==a[id],i==4,i==8);
    return res;
}
ll l,r;
int main(){Rosario
    cin>>l>>r;
    cout<<cal(r)-cal(l-1)<<"\n";
    return 0;
}
