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

struct qq{
    long double x,y,z;
    bool operator<(const qq &a)const{return z<a.z;}
}a[1005];
long double dist(qq x,qq y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y)+(x.z-y.z)*(x.z-y.z));}
ll t,n,ck=0;
double m,r;
bitset<1001> vis;
void dfs(ll x){
    if(a[x].z+r>=m) return ck=1,void();
    vis[x]=1;
    REP1(i,1,n){
        if(ck) return;
        if(!vis[i]&&dist(a[x],a[i])<=r+r) dfs(i);
    }
}
int main(){Rosario
    cin>>t;
    while(t--){ck=0;vis.reset();
        cin>>n>>m>>r;
        REP1(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z;
        sort(a+1,a+1+n);
        REP1(i,1,n) if(a[i].z-r<=0) dfs(i);
        cout<<(ck?"Yes":"No")<<"\n";
    }
    return 0;
}
