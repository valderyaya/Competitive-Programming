//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const int z=1e5+5;
struct qq{
    int a,b,c,cnt,ans;
    bool operator<(const qq &x){
        if(a!=x.a) return a<x.a;
        if(b!=x.b) return b<x.b;
        return c<x.c;
    }
}a[z],b[z];
int n,k,bit[z<<1],idx=0,cc[z],tp=0;
void add(int x,int v){ for(;x<=k;x+=lb(x)) bit[x]+=v; }
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
void cdq(int l,int r){
    if(l==r) return;
    int mid=l+r>>1,i,j,k=l;
    cdq(l,mid),cdq(mid+1,r);
    for(i=l,j=mid+1; i<=mid&&j<=r;)
        if(b[i].b<=b[j].b) {
            add(b[i].c,b[i].cnt);
            a[k++]=b[i++];
        }else {
            b[j].ans+=que(b[j].c);
            a[k++]=b[j++];
        }
    while(i<=mid) add(b[i].c,b[i].cnt),a[k++]=b[i++];
    while(j<=r) {
        b[j].ans+=que(b[j].c);
        a[k++]=b[j++];
    }
    REP1(i,l,mid) add(b[i].c,-b[i].cnt);
    REP1(i,l,r) b[i]=a[i];
}
int main(){//Rosario
	cin>>n>>k;
    REP1(i,1,n) cin>>a[i].a>>a[i].b>>a[i].c;
    sort(a+1,a+1+n);
    REP1(i,1,n){++tp;
        if(a[i].a!=a[i+1].a||a[i].b!=a[i+1].b||a[i].c!=a[i+1].c){
            b[++idx]=qq{a[i].a,a[i].b,a[i].c,tp,0};
            tp=0;
        }
    }
    // REP1(i,1,n) cout<<b[i].a<<" \n"[i==n];
    // REP1(i,1,n) cout<<b[i].b<<" \n"[i==n];
    // REP1(i,1,n) cout<<b[i].c<<" \n"[i==n];
    cdq(1,idx);
    //cout<<tp<<"\n";
    REP1(i,1,idx) cc[b[i].ans+b[i].cnt-1]+=b[i].cnt;
    REP(i,n) cout<<cc[i]<<"\n";
	return 0;
}
