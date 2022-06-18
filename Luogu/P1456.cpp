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

const int z=100005;
int n,m,pa[z],ls[z],rs[z],val[z],dis[z]={-1};
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
int merge(int x,int y){
    if(!x||!y) return x|y;
    if(val[x]<val[y]) swap(x,y);
    rs[x]=merge(rs[x],y); pa[rs[x]]=x;
    if(dis[ls[x]]<dis[rs[x]]) swap(ls[x],rs[x]);
    return dis[x]=dis[rs[x]]+1,x;
}
int f(int x){
    val[x]>>=1;
    int rt=merge(ls[x],rs[x]);
    dis[x]=ls[x]=rs[x]=0;
    return pa[x]=merge(rt,x);
}
void solve(int x,int y){
    x=f(x),y=f(y);
    pa[x]=pa[y]=merge(x,y);
    cout<<val[pa[x]]<<"\n";
}
int main(){Rosario
    while(cin>>n){
        REP1(i,1,n) pa[i]=i,cin>>val[i],ls[i]=rs[i]=dis[i]=0;
        cin>>m; int x,y;
        while(m--){
            cin>>x>>y;
            x=fin(x),y=fin(y);
            if(x==y) cout<<"-1\n";
            else solve(x,y);
        }
    }
    return 0;
}
