//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m;
struct group{int a[11],b[11],c[11];}g[52];
int main(){Rosario
    cin>>n>>m; int x;
    REP1(i,1,m){
        cin>>x;
        REP(j,n<<1|1) cin>>g[i].a[j];
        REP(j,n<<1|1) cin>>g[i].b[j];
        REP(j,n<<1|1) cin>>g[i].c[j];
    }
    for(int i=m;i;--i){x=1;
        REP1(j,1,m) if(i!=j){
            for(int k=0;k<n+1&&x;++k){
                if(g[i].a[k]<g[j].a[k+n]) x=0;
                if(g[i].a[k]==g[j].a[k+n]&&i>j) x=0;
            }
        }
        if(x) {cout<<i<<' ';break;}
    }
    for(int i=m;i;--i){x=1;
        REP1(j,1,m) if(i!=j){
            for(int k=0;k<n+1&&x;++k){
                if(g[i].b[k]<g[j].c[k+n]) x=0;
                if(g[i].b[k]==g[j].c[k+n]&&i>j) x=0;
            }
        }
        if(x) {cout<<i<<'\n';break;}
    }
    return 0;
}
