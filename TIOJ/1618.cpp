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

const int z=5e5+5;
int n,m,ans,b[z],a[z],que[z],l=0,r=0;
ll sum=0,mx=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n){
        while(l<r&&a[que[r-1]]<=a[i]) sum-=b[que[--r]];
        sum+=b[i]; que[r++]=i;
        while(que[l]<i-m+1) sum-=b[que[l++]];
        if(sum>mx) ans=i+1,mx=sum;
    }cout<<ans<<' '<<mx<<"\n";
    return 0;
}
