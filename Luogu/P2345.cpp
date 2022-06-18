//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

#define int ll
const int z=20000;
int n;
struct qq{
    int v,x;
    bool operator<(const qq &a)const{return v<a.v;}
}a[20005];
ll b[2][20005],ans=0;
void add(int x,int v){for(;x<=z;x+=lb(x)) b[0][x]+=v,b[1][x]++;}
pii que(int l,int r){
    int res=0,cnt=0;
    for(;r;r-=lb(r)) res+=b[0][r],cnt+=b[1][r];
    for(--l;l;l-=lb(l)) res-=b[0][l],cnt-=b[1][l];
    return mkp(res,cnt);
}
main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].v>>a[i].x;
    sort(a,a+n);
    //REP(i,n) cout<<a[i].v<<' '<<a[i].x<<endl;
    REP(i,n){
        pii x=que(1,a[i].x);
        ans+=a[i].v*(a[i].x*x.S-x.F);
        x=que(a[i].x,z);
        ans+=a[i].v*(x.F-a[i].x*x.S);
        add(a[i].x,a[i].x);
    }cout<<ans<<"\n";
    return 0;
}
