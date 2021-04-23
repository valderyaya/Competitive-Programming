//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
const int z=1e5+5,mod = 19999999999997;
int ls[z<<6],rs[z<<6],val[z<<6],cnt=0,n,m,a[z],rt[z<<1],ans[z],pw[z];
void build(int &p,int l,int r){
    if(!p) p=++cnt;
    if(l==r) return val[p]=a[l]*pw[l],void();
    int mid=l+r>>1;
    build(ls[p],l,mid); build(rs[p],mid+1,r);
    val[p]=(val[ls[p]]+val[rs[p]])%mod;
}
void modify(int &p,int pre,int l,int r,int x){
    p=++cnt;
    if(l==r) return val[p]=a[x]*pw[l],void();
    ls[p]=ls[pre], rs[p]=rs[pre];
    int mid=l+r>>1;
    if(x<=mid) modify(ls[p],ls[pre],l,mid,x);
    if(x>mid) modify(rs[p],rs[pre],mid+1,r,x);
    val[p]=(val[ls[p]]+val[rs[p]])%mod;
}
int query(int p,int pre,int l,int r){
    if(l==r){
        int x=val[p]/pw[l],y=val[pre]/pw[l];
        return x>y;
    }
    int mid=l+r>>1;
    if(val[ls[p]]!=val[ls[pre]]) return query(ls[p],ls[pre],l,mid);
    else return query(rs[p],rs[pre],mid+1,r);
}
bool cmp(int x,int y){
    return query(rt[y],rt[x],1,n);
}
// void print(int p,int l,int r){
//     if(l==r) return cout<<(val[p]/pw[l])<<' ',void();
//     int mid=l+r>>1;
//     print(ls[p],l,mid);print(rs[p],mid+1,r);
// }
main(){Rosario
    srand(time(0));
    cin>>n>>m;
    int x,y,idx=0,id=0;
    REP1(i,1,n) cin>>a[i],pw[i]=rand()+z;
    build(rt[0],1,n);
    ans[id++]=0;
    while(--m){
        cin>>x>>y;
        swap(a[x],a[y]);
        ++idx;
        modify(rt[idx],rt[idx-1],1,n,x);
        ++idx;
        modify(rt[idx],rt[idx-1],1,n,y);
        ans[id++]=idx;
    }
    stable_sort(ans,ans+id,cmp);
    REP(i,id) cout<<ans[i]/2<<' ';
    return 0;
}
