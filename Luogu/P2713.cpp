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

const int z=1e6+5;
int n,m,val[z],ls[z],rs[z],dis[z]={-1},pa[z];
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(val[a]>val[b]||(val[a]==val[b]&&a>b)) swap(a,b);
    rs[a]=merge(rs[a],b); pa[rs[a]]=a;
    if(dis[ls[a]]<dis[rs[a]]) swap(ls[a],rs[a]);
    return dis[a]=dis[rs[a]]+1,a;
}
void pop(int x){
    val[x]=-1;
    pa[ls[x]]=ls[x],pa[rs[x]]=rs[x];
    pa[x]=merge(ls[x],rs[x]);
}
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    cin>>n; char c;
    REP1(i,1,n) pa[i]=i,cin>>val[i];
    cin>>m; int x,y;
    while(m--){
        cin>>c;
        if(c=='K'){
            cin>>x;
            if(val[x]==-1) cout<<"0\n";
            else{
                x=fin(x);
                cout<<val[x]<<"\n";
                pop(x);
            }
        }else{
            cin>>x>>y;
            if(val[x]==-1||val[y]==-1) continue;
            x=fin(x),y=fin(y);
            if(x!=y) pa[x]=pa[y]=merge(x,y);
        }
    }
    return 0;
}
