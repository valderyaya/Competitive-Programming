//https://www.luogu.com.cn/problem/U109895


//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int tr[2][16000160],n,m,tot;
ll val[16000160];
ll q;
void ins(){
    int p=0,c;
    for(int i=32;~i;--i){
        c=q>>i&1;
        if(!tr[c][p]) tr[c][p]=++tot;
        p=tr[c][p];
    }
    val[p]=q;
}
ll qry(){
    ll res=0,c,p=0;
    for(ll i=32;~i;--i){
        c=q>>i&1;
        if(tr[c^1][p]){
            p=tr[c^1][p];
            res|=(1<<i);
        }else p=tr[c][p];
    }
    return val[p];
}
signed main(){Alicization
    cin>>n>>m;
    REP(i,n) cin>>q,ins();
    REP(i,m) cin>>q,cout<<qry()<<"\n";
    return 0;
}
