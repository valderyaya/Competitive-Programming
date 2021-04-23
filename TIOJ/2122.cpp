//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


struct qq{int l,r,sl,id,ans;}q[100005];
bool cmp(qq a,qq b){return a.id<b.id;}
bool cmp1(qq a,qq b){return a.sl==b.sl?a.r<b.r:a.sl<b.sl;}
int n,m,a[100005],sn,l,r,mx=0,c[100005]={},cnt[100005]={};
void add(int x){
    cnt[x]++;c[cnt[x]]++,c[cnt[x]-1]--;mx=max(mx,cnt[x]);
}
void sub(int x){
    cnt[x]--;c[cnt[x]]++,c[cnt[x]+1]--;
    while(c[mx]<=0) c[mx]=0,mx--;
}
int main(){Rosario
    cin>>n>>m;sn=sqrt(m);
    REP1(i,1,n) cin>>a[i];
    REP(i,m) cin>>q[i].l>>q[i].r,q[i].id=i,q[i].sl=q[i].l/sn;
    sort(q,q+m,cmp1);l=r=0;
    REP(i,m){
        while(l<q[i].l) sub(a[l++]);
        while(l>q[i].l) add(a[--l]);
        while(r<q[i].r) add(a[++r]);
        while(r>q[i].r) sub(a[r--]);
        q[i].ans=mx;
    }sort(q,q+m,cmp);
    REP(i,m) cout<<q[i].ans<<"\n";//printf("%d\n",q[i].ans);
//    system("pause");
    return 0;
}
