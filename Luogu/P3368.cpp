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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m,a[500005];
void add(int x,int v){
    for(;x<=n;x+=lb(x)) a[x]+=v;
}
int qry(int x){
    int r=0;
    for(;x;x-=lb(x)) r+=a[x];
    return r;
}
signed main(){Rosario
    cin>>n>>m;
    for(int p=0,x,i=1;i<=n;++i) cin>>x,add(i,x-p),p=x;
    for(int x,y,k,op;m;--m){
        cin>>op>>x;
        if(op==1) cin>>y>>k,add(x,k),add(y+1,-k);
        else cout<<qry(x)<<"\n";
    }
    return 0;
}
