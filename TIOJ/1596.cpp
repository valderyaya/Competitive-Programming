//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

const int z=1e5+2;
struct qq{
    int a,b,c;
    bool operator<(const qq &x){return c>x.c;}
}q[z];
bitset<z> is;
int n,m,p[z],qe;
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int main(){Rosario
    cin>>n>>m; int a,b,c=0;
    REP1(i,1,n) p[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c,c+=q[i].c;
    cin>>qe; sort(q,q+m);
    while(qe--) cin>>a,is[a]=1;
    REP(i,m){
        a=fin(q[i].a),b=fin(q[i].b);
        if(is[a]&&is[b]) continue;
        p[a]=b; c-=q[i].c;
        if(is[a]||is[b]) is[a]=is[b]=1;
    }cout<<c<<"\n";
    return 0;
}
