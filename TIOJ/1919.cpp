//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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
#define lb(x) (x&-x)

struct qq{
    ll l,r,v;
    bool operator<(const qq &a)const{
        return l<a.l;
    }
}q[100005],Q[100005],mod[100005];
vector<ll> v[100005];
ll ms[100005],goal[100005],ans[100005],tmp[100005],bit[100005],n,m,p,last[100005],R[100005];
void add(ll x,ll v){
    for(;x<=m;x+=lb(x)) bit[x]+=v;
}
ll que(ll x){
    ll ret=0;
    for(;x;x-=lb(x)) ret+=bit[x];
    return ret;
}
void solve(ll l,ll r,vector<ll> a){
    if(l==r){
        for(ll i:a) ans[i]=l;
        return;
    }
    ll mid=l+r>>1,c=0,cnt=0,now=0;
    vector<ll> q1,q2;
    REP1(i,l,mid) if(i) mod[c++]=Q[i];
    for(ll i:a){
        for(ll j:v[i]) q[cnt++]=qq{j,R[j],i};
        tmp[i]=0;
    }
    sort(q,q+cnt),sort(mod,mod+c);
    REP(i,cnt){
        while(now<c&&mod[now].l<=q[i].l) add(mod[now].r,mod[now].v),now++;
        tmp[q[i].v]+=que(q[i].r-1)-que(q[i].l-1);
    }
    REP(i,now) add(mod[i].r,-mod[i].v); 
    for(ll i:a){
        if(tmp[i]<goal[i]) goal[i]-=tmp[i],q2.em(i);
        else q1.em(i);
    }
    if(!q1.empty()) solve(l,mid,q1);
    if(!q2.empty()) solve(mid+1,r,q2);
}
vector<ll> a;
int main(){Rosario
    cin>>n>>m>>p;
    REP1(i,1,m) cin>>ms[i],last[ms[i]]=m+1,v[ms[i]].em(i);
    for(int i=m;i>0;i--) R[i]=last[ms[i]],last[ms[i]]=i;
    REP1(i,1,n) cin>>goal[i],a.em(i);
    REP1(i,1,p) cin>>Q[i].l>>Q[i].r>>Q[i].v;
    solve(0,p+1,a);
    REP1(i,1,n) cout<<(ans[i]==p+1?-1:ans[i])<<"\n";
//    system("pause");
    return 0;
}
