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

struct qq{
    int l,r,id;
    bool operator<(const qq &a)const{
        return r<a.r;
    }
}q[1000005];
int n,m,on[1000005],bit[1000005],a[1000005],ans[1000005];
void add(int x,int v){
    for(;x<=n;x+=lb(x)) bit[x]+=v;
}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    cin>>m;
    REP1(i,1,m) cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m);
    int now=1;
    REP1(i,1,m){
        while(now<=q[i].r){
            if(on[a[now]]) add(on[a[now]],-1);
            add(now,1);on[a[now]]=now;now++;
        }ans[q[i].id]=que(q[i].r)-que(q[i].l-1);
    }
    REP1(i,1,m) cout<<ans[i]<<'\n';
//    system("pause");
    return 0;
}
