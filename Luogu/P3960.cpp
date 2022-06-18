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
const int z=3e5+5;
int cnt[z],tot,n,m,q,ls[z<<5],x,y,rs[z<<5],val[z<<5],sz[z<<5],rt[z],ff;
void upda(int &o,int l,int r,int k,int pos){
    if(!o) o=++tot;
    if(l==r) return val[o]=k,void();
    int mid=l+r>>1;
    if(pos<=mid) upda(ls[o],l,mid,k,pos);
    else upda(rs[o],mid+1,r,k,pos);
}
int qry(int &o,int l,int r,int k){
    if(!o) o=++tot;
    sz[o]++;
    if(l==r){
        if(val[o]) return val[o];
        else if(ff) return (x-1)*m+l;
        return l*m;
    }
    int mid=l+r>>1,now=(mid-l+1)-sz[ls[o]];
    if(now>=k) return qry(ls[o],l,mid,k);
    else return qry(rs[o],mid+1,r,k-now);
}
signed main(){Rosario
    cin>>n>>m>>q; int p,tp;
    REP1(i,1,q){
        cin>>x>>y;
        if(y==m){
            ff=0; p=qry(rt[n+1],1,n+q,x);
            cout<<p<<"\n";
            upda(rt[n+1],1,n+q,p,++cnt[n+1]+n);
        }else{
            ff=1; p=qry(rt[x],1,m+q-1,y);
            cout<<p<<"\n";
            ff=0; tp=qry(rt[n+1],1,n+q,x);
            upda(rt[x],1,m+q-1,tp,++cnt[x]+m-1);
            upda(rt[n+1],1,n+q,p,++cnt[n+1]+n);
        }
    }
    return 0;
}
