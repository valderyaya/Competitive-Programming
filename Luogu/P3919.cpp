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
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int maxn=1000001;
int n,m,ls[maxn<<5],rs[maxn<<5],val[maxn<<5],a[maxn],cnt=0,root[maxn<<5];
int build(int l,int r){
    int x=++cnt,mid=l+r>>1;
    if(l==r) return val[x]=a[l],x;
    ls[x]=build(l,mid);
    rs[x]=build(mid+1,r);
    return x;
}
int add(int l,int r,int rt,int x,int z){
    int dr=++cnt,mid=l+r>>1;
    ls[dr]=ls[rt],rs[dr]=rs[rt];
    if(l==r) return val[dr]=z,dr;
    if(x<=mid) ls[dr]=add(l,mid,ls[rt],x,z);
    else rs[dr]=add(mid+1,r,rs[rt],x,z);
    return dr;
}
int query(int l,int r,int rt,int x){
    if(l==r) return val[rt];
    int mid=l+r>>1;
    if(x<=mid) return query(l,mid,ls[rt],x);
    else return query(mid+1,r,rs[rt],x);
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    root[0]=build(1,n);
    int k,x,y,z;
    REP1(i,1,m){
        cin>>x>>k>>y;
        if(k&1) cin>>z,root[i]=add(1,n,root[x],y,z);
        else root[i]=root[x],cout<<query(1,n,root[x],y)<<"\n";
    }
//    system("pause");
    return 0;
}
