#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

const int z=2e5+1;
int n,q,cnt,val[z<<5],ls[z<<5],rs[z<<5],root[z];
void build(int l,int r,int &o){
    o=++cnt;int mid=l+r>>1;
    val[o]=0;
    if(l==r) return ;
    build(l,mid,ls[o]);
    build(mid+1,r,rs[o]);
}
void add(int l,int r,int &o,int lst,int x){
    o=++cnt;
    ls[o]=ls[lst], rs[o]=rs[lst], val[o]=val[lst]+1;
    if(l==r) return ;
    int mid=l+r>>1;
    if(x<=mid) add(l,mid,ls[o],ls[lst],x);
    else add(mid+1,r,rs[o],rs[lst],x); 
}
int qry(int l,int r,int x,int L,int R){
    //cout<<val[L]<<' '<<val[R]<<endl;
    if(l==r) return val[R]-val[L];
    int mid=l+r>>1;
    if(x<=mid) return qry(l,mid,x,ls[L],ls[R]);
    return qry(mid+1,r,x,rs[L],rs[R]);
}
signed main(){valder
    cin>>n;
    build(1,n,root[0]);
    for(int x,i=1;i<=n;++i){
        cin>>x;
        add(1,n,root[i],root[i-1],x);
    }
    cin>>q;
    for(int l,r,x;q--;){
        cin>>l>>r>>x;
        cout<<qry(1,n,x,root[l-1],root[r])<<"\n";
    }
}
