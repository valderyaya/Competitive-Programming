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
struct qq{
    int t,x,y;
    bool operator<(const qq &a)const{return t<a.t;}
}a[100005],b[100005];
int n,m,bit[100005],ans[100005],pos[100005];
void add(int x,int v){for(;x<=n;x+=lb(x)) bit[x]+=v;}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
void cdq(int l,int r){
    if(l==r) return;
    int mid=l+r>>1,i,j,k;
    cdq(l,mid); cdq(mid+1,r);
    for(i=l,j=mid+1,k=l;i<=mid||j<=r;++k)
        if(j>r||(i<=mid&&a[i].x<a[j].x)) add(a[i].y,1),b[k]=a[i++];
        else ans[a[j].t]+=que(n)-que(a[j].y),b[k]=a[j++];
    REP1(i,l,mid) add(a[i].y,-1);
    REP1(i,l,r) a[i]=b[i];
    for(int i=r;i>=l;--i)
        if(a[i].t<=mid) add(a[i].y,1);
        else ans[a[i].t]+=que(a[i].y);
    REP1(i,l,r) if(a[i].t<=mid) add(a[i].y,-1);
}
 main(){Rosario
    cin>>n>>m;
    int tme=n,x;
    REP1(i,1,n) cin>>x,a[i]=qq{0,pos[x]=i,x};
    REP1(i,1,m) cin>>x,a[pos[x]].t=tme--;
    REP1(i,1,n) if(!a[i].t) a[i].t=tme--;
    sort(a+1,a+1+n);  cdq(1,n);
    REP1(i,1,n) ans[i]+=ans[i-1];
    for(int i=n;i>=n-m+1;--i) cout<<ans[i]<<"\n";
    return 0;
}
