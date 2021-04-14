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
//#define line cout<<"-------------------------\n";

#define int ll
const int z=1000005,mod=1000000009;
int n,bit[2][z],b[z]={},m;
pll a[z];
void add(int x,int v){
    for(;x<=m;x+=lb(x)){
        bit[0][x]+=v;
        bit[0][x]%=mod;
        bit[1][x]++;
    }
}
pll que(int x){
    int re=0,res=0;
    for(;x;x-=lb(x)){
        re+=bit[0][x];
        re%=mod;
        res+=bit[1][x];
    }
    return mkp(re,res);
}
main(){Rosario
    cin>>n;
    int ans=0,x;
    REP(i,n) cin>>a[i].F>>a[i].S,b[i]=a[i].S;
    sort(a,a+n); sort(b,b+n); m=unique(b,b+n)-b;
    REP(i,n){
        x=lower_bound(b,b+m,a[i].S)-b+1;
        pll re=que(x);
        ans+=(a[i].F*a[i].S%mod*re.S%mod-re.F+mod)%mod;
        ans%=mod;
        add(x,a[i].F%mod*a[i].S%mod);
    }cout<<ans%mod;
//    system("pause");
    return 0;
}
