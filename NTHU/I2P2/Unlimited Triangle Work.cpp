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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int t,a,b,c,d,s[100005];
ll ans;
signed main(){Aincrad
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        memset(s,0,sizeof(s));
        for(int i=a;i<=b;++i) {
            s[i+b]++;
            s[i+c+1]--;
        }
        for(int i=1;i<=100000;++i) s[i]+=s[i-1];
        ans=0;
        for(int i=1;i<=100000;++i) ans+=min(d-c+1,max(i-c,0))*s[i];
        cout<<ans<<"\n";
    }
    return 0;
}
