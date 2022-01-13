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

int n,r,pa[1001],c[2];
pii a[1001];
int cal(int i,int j){return (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S);}
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
bitset<1001> vis;
signed main(){
    cin>>n>>r; r*=r;
    REP1(i,1,n) cin>>a[i].F>>a[i].S,pa[i]=i;
    REP1(i,1,n) REP1(j,i+1,n){
        if(fin(i)==fin(j)) continue;
        int dis=cal(i,j);
        if(dis<=r) pa[fin(i)]=fin(j),vis[i]=vis[j]=1;
    }
    REP1(i,1,n) if(pa[i]==i) c[vis[i]]++;
    cout<<c[0]<<' '<<c[1]<<"\n";
    return 0;
}
