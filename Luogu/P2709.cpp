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
//#define lb(x) (x&-x)

struct qq{
    int l,r,id,sl;
    bool operator<(const qq &a)const{
        return sl==a.sl?r<a.r:sl<a.sl;
    }
}q[50005];
int cnt[50005]={},now=1,a[50005],ans[50005],n,m,k,sq;
inline void add(int x){
    now-=cnt[x]*cnt[x];
    cnt[x]++;
    now+=cnt[x]*cnt[x];
}
inline void sub(int x){
    now-=cnt[x]*cnt[x];
    cnt[x]--;
    now+=cnt[x]*cnt[x];
}
inline void solve(){
    int l=1,r=1;cnt[a[1]]++;
    REP(i,m){
        while(r<q[i].r) add(a[++r]);
        while(r>q[i].r) sub(a[r--]);
        while(l<q[i].l) sub(a[l++]);
        while(l>q[i].l) add(a[--l]);
        ans[q[i].id]=now;
    }
}
int main(){Rosario
    cin>>n>>m>>k;sq=sqrt(n)+1;
    REP1(i,1,n) cin>>a[i];
    REP(i,m) cin>>q[i].l>>q[i].r,q[i].sl=q[i].l/sq,q[i].id=i;
    sort(q,q+m);solve();
    REP(i,m) cout<<ans[i]<<"\n";
//    system("pause");
    return 0;
}
