#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

ll max_(ll x,ll y){return x>y?x:y;}
ll mx=0,n,m,pa[100005],r[100005],sum[100005],v[100005];
__gnu_pbds::priority_queue<ll> q[100005];
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>pa[i]>>v[i]>>r[i],sum[i]=v[i];
    for(int i=n;i;i--){
        q[i].push(v[i]);
        while(sum[i]>m) sum[i]-=q[i].top(),q[i].pop();
        mx=max_(mx,q[i].size()*r[i]);
        sum[pa[i]]+=sum[i];q[pa[i]].join(q[i]);
    }cout<<mx<<"\n";
//    system("pause");
    return 0;
}
