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

const int z=105;
int n,m,a[z<<2];
void build(int l,int r,int rt){
    if(l==r) return a[rt]=1,void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}
int que(int l,int r,int rt,int x){
    if(l==r) return l;
    int mid=l+r>>1;
    if(x<=a[rt<<1]) return que(l,mid,rt<<1,x);
    else return que(mid+1,r,rt<<1|1,x-a[rt<<1]);
}
void mod(int l,int r,int x,int rt){
    if(l==r) return a[rt]=0,void();
    int mid=l+r>>1;
    if(x<=mid) mod(l,mid,x,rt<<1);
    else mod(mid+1,r,x,rt<<1|1);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}
int main(){Rosario
    cin>>n>>m; int now=1,p=n;
    build(1,n,1);
    while(p--){
        now=(now+m-2)%a[1]+1;
        int x=que(1,n,1,now);
        cout<<x<<" ";
        mod(1,n,x,1);
    }
    return 0;
}
