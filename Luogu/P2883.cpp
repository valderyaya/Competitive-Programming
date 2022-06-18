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
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
int n,m,in[5005],cnt[5005],ans,out[5005],tot[5005];
vector<int> v[5005];
signed main(){Alicization
    cin>>n>>m;
    for(int x,y;m;--m){
        cin>>x>>y;
        v[x].em(y);
        ++in[y];
        ++out[x];
    }
    REP1(i,1,n){
        if(in[i]==0) cnt[i]=1;
        if(out[i]==0) tot[i]=1;
    }
    REP1(i,1,n) for(auto&j:v[i]) cnt[j]+=cnt[i];
    for(int i=n;i;--i) for(auto &j:v[i]) tot[i]+=tot[j];
    REP1(i,1,n) for(auto &j:v[i]) ans=max(ans,cnt[i]*tot[j]);
    cout<<ans;
    return 0;
}
