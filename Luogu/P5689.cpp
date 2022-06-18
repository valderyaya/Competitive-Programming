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
//#define lb(x) (x&-x)

#define int ll
const int md=1e9+7,z=3e5+5;
int power(int a,int n){
    int res=1;
    for(a%=md;n;n>>=1,a=a*a%md) if(n&1) res=res*a%md;
    return res;
}
int n,m,sz[z],fa[z],inv[z],ans[z],f[z];
int fin(int x){return x==fa[x]?x:fa[x]=fin(fa[x]);}
void build(){
    REP(i,n) fa[i]=i,sz[i]=1,ans[i]=1;
    f[0]=f[1]=1;
    for(int i=2;i<=n;++i) f[i]=f[i-1]*i%md;
    inv[n]=power(f[n],md-2);
    for(int i=n-1;~i;--i) inv[i]=inv[i+1]*(i+1)%md;
}
int C(int x,int y){
    return f[x]*inv[y]%md*inv[x-y]%md;
}
void merge(int x,int y){
    x=fin(x),y=fin(y);
    if(x!=y){
        fa[x]=y;
        sz[y]+=sz[x];
        ans[y]=ans[x]*ans[y]%md*C(sz[y]-1,sz[x])%md;
    }
}
main(){Rosario
    cin>>n>>m;
    build();
    for(int prv=0,x,y,op;m;--m){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            x=(x+prv)%n, y=(y+prv)%n;
            merge(x,y);
        }else{
            cin>>x;
            x=(x+prv)%n;
            prv=ans[fin(x)];
            cout<<prv<<"\n";
        }
    }
    return 0;
}
