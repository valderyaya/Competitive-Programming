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
 
int n,q;
vector<pii> v;
signed main(){Aincrad
    cin>>n>>q;
    for(int x,i=1;i<=n;++i) cin>>x,v.em(x,i);
    sort(ALL(v));
    REP1(i,0,n-1) REP1(j,i+1,n-1){
      int mid,x=q-v[i].F-v[j].F,l=j+1,r=n-1;
      if(l==r&&v[l].F==x) return cout<<v[i].S<<' '<<v[j].S<<' '<<v[l].S<<"\n",0;
      while(l<r){
        mid=l+r>>1;
        if(v[mid].F==x) return cout<<v[i].S<<' '<<v[j].S<<' '<<v[mid].S<<"\n",0;
        if(v[mid].F>x) r=mid;
        else l=mid+1;
      }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
