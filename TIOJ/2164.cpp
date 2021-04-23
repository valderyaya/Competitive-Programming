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

ll n,dd[5005],ans;
struct qq{ll x,y,z;}q[5005];
ll dis(int i,int j){return (q[i].x-q[j].x)*(q[i].x-q[j].x)+(q[i].y-q[j].y)*(q[i].y-q[j].y)+(q[i].z-q[j].z)*(q[i].z-q[j].z);}
bitset<5005> vis;
void prim(){
    dd[0]=0; ll mi,pos;
    REP(i,n){
        mi=1e16;
        REP(j,n) if(!vis[j]&&dd[j]<mi) mi=dd[j],pos=j;
        ans+=mi; vis[pos]=1;
        REP(j,n) dd[j]=min(dd[j],dis(pos,j));
    }
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].x>>q[i].y>>q[i].z,dd[i]=1e16;
    prim(); cout<<ans<<"\n"; 
    return 0;
}
