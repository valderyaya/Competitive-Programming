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

const int maxn=200001;
int n,m,ls[maxn<<5],rs[maxn<<5],sum[maxn<<5],a[maxn],b[maxn],c[maxn],cnt=0;
int build(int l,int r){
    int x=++cnt,mid=l+r>>1;sum[x]=0;
    if(l==r) return x;
    ls[x]=build(l,mid);
    rs[x]=build(mid+1,r);
    return x;
}
int add(int l,int r,int rt,int x){
    int dr=++cnt,mid=l+r>>1;
    ls[dr]=ls[rt],rs[dr]=rs[rt],sum[dr]=sum[rt]+1;
    if(l==r) return dr;
    if(x<=mid) ls[dr]=add(l,mid,ls[rt],x);
    else rs[dr]=add(mid+1,r,rs[rt],x);
    return dr;
}
int query(int L,int R,int l,int r,int k){
    if(l==r) return l;
    int x=sum[ls[R]]-sum[ls[L]],mid=l+r>>1;
    if(x>=k) return query(ls[L],ls[R],l,mid,k);
    else return query(rs[L],rs[R],mid+1,r,k-x);
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b-1;
    c[0]=build(1,len);
    REP1(i,1,n) c[i]=add(1,len,c[i-1],lower_bound(b+1,b+1+len,a[i])-b);
    int l,r,k;
    while(m--){
        cin>>l>>r>>k;
        cout<<b[query(c[l-1],c[r],1,len,k)]<<"\n";
    }
//    system("pause");
    return 0;
}
