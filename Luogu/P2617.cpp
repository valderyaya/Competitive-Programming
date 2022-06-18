#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define wait system("pause");

int n,m,b[100005],ans[100005],a[100005];
void add(int x,int v){for(;x<=n;x+=lb(x)) b[x]+=v;}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[x];
    return res;
}//1 que
struct qq{int x,y,k,ty,id;}q[300005],q1[300005],q2[300005];
void solve(int l,int r,int ql,int qr){
    if(ql>qr) return;
    if(l==r){
        REP1(i,ql,qr) if(q[i].ty) ans[q[i].id]=l;
        return;
    }int mid=l+r>>1,cnt=ql-1,cnt1=0,cnt2=0;
    REP1(i,ql,qr){
        if(q[i].ty){
            int r=que(q[i].y)-que(q[i].x-1);
            if(q[i].k<=r) q1[++cnt1]=q[i];
            else q[i].k-=r,q2[++cnt2]=q[i];
        }else {
            if(q[i].y<=mid) add(q[i].x,q[i].k),q1[++cnt1]=q[i];
            else q2[++cnt2]=q[i];
        }
    }
    REP1(i,1,cnt1){
        if(!q1[i].ty) add(q1[i].x,-q1[i].k);
        q[++cnt]=q1[i];
    }
    REP1(i,1,cnt2) q[++cnt]=q2[i];
    solve(l,mid,ql,ql+cnt1-1);solve(mid+1,r,ql+cnt1,qr);
}
int main(){Rosario
    cin>>n>>m;
    char c;
    int cnt=0,len=0,x,y,k;
    REP1(i,1,n) cin>>a[i],q[++len]=qq{i,a[i],1,0};
    REP(i,m){
        cin>>c;
        if(c=='Q') cin>>x>>y>>k,q[++len]=qq{x,y,k,1,++cnt};
        else cin>>x>>y,q[++len]=qq{x,a[x],-1,0},q[++len]=qq{x,a[x]=y,1,0};
    }
    solve(1,1e9,1,len);
    REP1(i,1,cnt) cout<<ans[i]<<'\n';
//    wait
    return 0;
}
