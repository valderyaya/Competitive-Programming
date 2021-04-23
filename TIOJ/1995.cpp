//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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


const int z=2500001,zz=1000001;
int a[z],n,m;
pii q[zz];
int main(){//Rosario
    scanf("%d",&n),scanf("%d",&m);
    REP(i,m) scanf("%d",&q[i].F),scanf("%d",&q[i].S),--q[i].F,--q[i].S;
    REP(i,n) scanf("%d",&a[i]);
    for(int i=0;(1<<i)<=n;++i){
        REP(j,m){
            if(!~q[j].S) continue;
            int lg=31-__builtin_clz(q[j].S-q[j].F+1);
            if(i!=lg) continue;
            q[j].F=max(a[q[j].F],a[q[j].S-(1<<lg)+1]); q[j].S=-1;
        }
        for(int j=0;j+(1<<(i+1))<=n;j++) a[j]=max(a[j],a[j+(1<<i)]);
    }
    REP(i,m) printf("%d\n",q[i].F);
    return 0;
}
