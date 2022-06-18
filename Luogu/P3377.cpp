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

const int z=1e5+5;
int pa[z],val[z],ls[z],rs[z],dis[z]={-1},n,m;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int merge(int x,int y){
    if(!x||!y) return x|y;
    if(val[x]>val[y]||(val[x]==val[y]&&x>y)) swap(x,y);
    rs[x]=merge(rs[x],y);  pa[rs[x]]=x;
    if(dis[ls[x]]<dis[rs[x]]) swap(ls[x],rs[x]);
    dis[x]=dis[rs[x]]+1;  return x;
}
void pop(int x){
    val[x]=-1;
    pa[ls[x]]=ls[x],pa[rs[x]]=rs[x];
    pa[x]=merge(ls[x],rs[x]);
}
int main(){Rosario
    cin>>n>>m; int x,y,k;
    REP1(i,1,n) cin>>val[i],pa[i]=i;
    while(m--){
        cin>>k>>x;
        if(k==1){
            cin>>y;
            if(val[x]==-1||val[y]==-1) continue;
            x=fin(x),y=fin(y);
            if(x!=y) pa[x]=pa[y]=merge(x,y);
        }else{
            if(val[x]==-1) cout<<"-1\n";
            else{
                x=fin(x);
                cout<<val[x]<<"\n";
                pop(x);
            }
        }
    }
    return 0;
}
