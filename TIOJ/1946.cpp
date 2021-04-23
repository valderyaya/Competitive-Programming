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

const int inf=1e9;
int a[1000005],n,b[1000005],mn[1000005],mx=0,c[1000005]={};
void add(int i){for(;i<=n;i+=lb(i))b[i]++;}
int sum(int x){int r=0;for(;x;x-=lb(x))r+=b[x];return r;}
int kth(int x){
    int res=0,cnt=0;
    for(int i=20;~i;i--){
        res+=(1<<i);
        if(res>n||cnt+b[res]>=x) res-=(1<<i);
        else cnt+=b[res];
    }
    return ++res;
}
int main(){Rosario
    cin>>n;int x;
    REP1(i,1,n){cin>>a[i];add(++a[i]);
        x=sum(a[i]);
        if(x!=i) mn[i]=kth(x+(i-x+1)/2);
        else mn[i]=inf;
    }memset(b,0,sizeof(b));
    for(int i=n;i;--i){add(a[i]);
        x=sum(a[i]);
        if(x!=n-i+1) mn[i]=min(mn[i],kth(x+(n-i+2-x)/2));
        if(mn[i]!=inf){
            if(++c[mn[i]]>c[mx]) mx=mn[i];
            if(++c[a[i]]>c[mx]) mx=i;
        }
    }cout<<c[mx]<<"\n";
//    REP1(i,1,n) cout<<mn[i]<<" \n"[i==n];
    return 0;
}
