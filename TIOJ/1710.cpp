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

#define int ll
int t,n,a[50005],b[2][50005],c[50005];
void add(int id,int x,int o){
    for(;x<=n;x+=lb(x)) b[id][x]+=o;
}
int que(int id,int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[id][x];
    return res;
}
main(){Rosario
    cin>>t;
    while(t--){
        cin>>n; 
        int ans=0;
        REP1(i,1,n) cin>>a[i],c[i]=a[i],b[0][i]=b[1][i]=0;
        sort(c+1,c+1+n);  int len=unique(c+1,c+1+n)-c-1;
        REP1(i,1,n){a[i]=lower_bound(c+1,c+1+len,a[i])-c;
            add(0,a[i],1);  add(1,a[i],que(0,a[i]-1));
            ans+=que(1,a[i]-1);
        }
        REP1(i,1,n) b[0][i]=b[1][i]=0;
        for(int i=n;i;--i){
            add(0,a[i],1); add(1,a[i],que(0,a[i]-1));
            ans+=que(1,a[i]-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
