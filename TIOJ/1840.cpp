#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

struct qq{ll x,y,k,t,id;}q[70005],q1[70005],q2[70005];
ll t,n,m,ans[10005],bit[50005],a[50005];
void add(ll x,ll v){
    for(;x<=n;x+=lb(x)) bit[x]+=v;
}
ll que(ll x){
    ll ret=0;
    for(;x;x-=lb(x)) ret+=bit[x];
    return ret;
}
void solve(ll l,ll r,ll ql,ll qr){
    if(ql>qr) return;
    if(l==r){
        REP1(i,ql,qr) if(q[i].t) ans[q[i].id]=l;
        return;
    }
    ll mid=l+r>>1,cnt=ql-1,cnt1=0,cnt2=0;
    REP1(i,ql,qr){
        if(q[i].t){
            ll r=que(q[i].y)-que(q[i].x-1);
            if(q[i].k<=r) q1[++cnt1]=q[i];
            else q[i].k-=r,q2[++cnt2]=q[i];
        }else{
            if(q[i].y<=mid) add(q[i].x,q[i].k),q1[++cnt1]=q[i];
            else q2[++cnt2]=q[i];
        }
    }
    REP1(i,1,cnt1){
        q[++cnt]=q1[i];
        if(q1[i].t==0) add(q1[i].x,-q1[i].k);
    }
    REP1(i,1,cnt2) q[++cnt]=q2[i];
    solve(l,mid,ql,ql+cnt1-1),solve(mid+1,r,ql+cnt1,qr);
}
int main(){Rosario
    cin>>t;
    while(t--){
        int len=0,cnt=0;
        cin>>n>>m;
        REP1(i,1,n) cin>>a[i],q[++len]=qq{i,a[i],1,0};
        for(ll l,r,tag,k,i=1;i<=m;i++){
            cin>>tag>>l>>r;
            if(tag==1) cin>>k,q[++len]=qq{l,r,k,1,++cnt};
            else if(tag==2) q[++len]=qq{l,a[l],-1,0},q[++len]=qq{l,a[l]=r,1,0};
            else ans[++cnt]=7122;
        }
        solve((ll)-2147483647,(ll)2147483647,1,len);
        REP1(i,1,cnt) cout<<ans[i]<<"\n";
    }
//    system("pause");
    return 0;
}
