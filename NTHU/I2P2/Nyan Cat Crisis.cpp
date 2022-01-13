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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,r,k,t,pa[505],sz[505];
pii a[505];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
int cal(int i,int j){
    return (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S);
}
void un(int i,int j){
    int x=fin(i),y=fin(j);
    if(x==y||cal(i,j)>r) return ;
    pa[x]=y, sz[y]+=sz[x];
}
signed main(){Aincrad
    cin>>t;
    while(t--){
        cin>>n>>r>>k;
        r*=r;
        REP1(i,1,n) pa[i]=i,sz[i]=1,cin>>a[i].F>>a[i].S;
        REP1(i,1,n) for(int j=i+1;j<=n;++j) un(i,j);
        int x=0,y=0;
        REP1(i,1,n) if(pa[i]==i){
            if(sz[i]<k) ++x;
            else ++y;
        }
        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}
