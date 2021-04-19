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

ll st,in[255],ed,n,m,mod,sum[255];
vector<ll> v[255];
int main(){Rosario
    cin>>n>>m>>mod;
    ll a,b; queue<ll> q;
    REP(i,m) cin>>a>>b,v[a].em(b),in[b]++;
    cin>>st>>ed; sum[st]=1;
    REP(i,n) if(!in[i]) q.emplace(i);
    while(!q.empty()){
        a=q.front();q.pop();
        for(auto &i:v[a]){
            sum[i]=(sum[i]+sum[a])%mod;
            if(--in[i]==0) q.emplace(i);
        }
    }cout<<sum[ed]<<"\n";
    return 0;
}
