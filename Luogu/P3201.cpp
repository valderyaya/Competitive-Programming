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
#define lb(x) (x&-x)
#define wait system("pause");

const int z=1e6+1,zz=4000000;
int ls[zz],n,m,rs[zz],cnt,R[zz],L[zz],sum[zz],rt[z],ans;
void up(int x){
    L[x]= ls[x]?L[ls[x]]:L[rs[x]];
    R[x]= rs[x]?R[rs[x]]:R[ls[x]];
    sum[x]= sum[ls[x]]+sum[rs[x]]-(R[ls[x]]+1==L[rs[x]]);
}
void modify(int &rt,int l,int r,int x){
    if(!rt) rt=++cnt;
    if(l==r) return L[rt]=R[rt]=l,sum[rt]=1,void();
    int mid=l+r>>1;
    if(x<=mid) modify(ls[rt],l,mid,x);
    else modify(rs[rt],mid+1,r,x);
    up(rt);
}
int merge(int a,int b,int l,int r){
    if(!a||!b) return a|b;
    if(l==r) return sum[a]+=sum[b],L[a]=R[a]=l,a;
    int mid=l+r>>1;
    ls[a]=merge(ls[a],ls[b],l,mid);
    rs[a]=merge(rs[a],rs[b],mid+1,r);
    up(a); return a;
}
int main(){Rosario
    cin>>n>>m;
    int x,op,y;
    REP1(i,1,n){
        cin>>x; ans-=sum[rt[x]];
        modify(rt[x],1,n,i);
        ans+=sum[rt[x]];
    }
    while(m--){
        cin>>op;
        if(op==2) cout<<ans<<"\n";
        else{
            cin>>x>>y;
            if(x==y) continue;
            ans-=sum[rt[x]]+sum[rt[y]];
            rt[y]=merge(rt[y],rt[x],1,n);
            rt[x]=0; ans+=sum[rt[y]];
        }
    }
    return 0;
}
