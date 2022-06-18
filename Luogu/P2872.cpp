//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";


struct qq{
    ll a,b;
    double c;
    bool operator<(const qq &x)const{
        return c<x.c;
    }
}q[1000005];
ll pa[1001],n,m,cnt,idx=0;
pll p[1001];
double ans;
double dis(ll a,ll b){
    ll x=p[a].F-p[b].F,y=p[a].S-p[b].S;
    return sqrt(x*x+y*y);
}
ll fin(ll x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    cin>>n>>m;
    cnt=n;
    ll a,b;
    REP1(i,1,n) cin>>p[i].F>>p[i].S,pa[i]=i;
    REP(i,m){
        cin>>a>>b;
        a=fin(a),b=fin(b);
        if(a!=b) cnt--,pa[a]=b;
    }
    REP1(i,1,n) REP1(j,1,n) if(pa[i]!=pa[b]) q[idx++]=qq{i,j,dis(i,j)};
    sort(q,q+idx);
    REP(i,idx){
        if(cnt==0)break;
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b) cnt--,pa[a]=b,ans+=q[i].c;
    }
    cout<<fixed<<setprecision(2)<<ans<<"\n";
//    system("pause");
    return 0;
}
