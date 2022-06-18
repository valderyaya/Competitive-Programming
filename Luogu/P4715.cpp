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
#define wait system("pause");

int n,x[200];
pii a[512<<2];
void up(int rt){
    if(x[a[rt<<1].F]>x[a[rt<<1|1].F]) a[rt].F=a[rt<<1].F,a[rt].S=a[rt<<1|1].F;
    else  a[rt].F=a[rt<<1|1].F,a[rt].S=a[rt<<1].F;
}
void build(int l,int r,int rt){
    if(l==r) return a[rt].F=l,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    up(rt);
}
int main(){Rosario
    cin>>n; n=1<<n;
    REP1(i,1,n) cin>>x[i];
    build(1,n,1);
    cout<<a[1].S<<"\n";   
//    system("pause");
    return 0;
}
