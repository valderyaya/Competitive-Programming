#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,a,b,c,x[1000005]={},dp[1000005]={};
vector<ll> v;
inline ll ret(ll i,ll j){return -2*a*x[i]*x[j]+a*x[j]*x[j]-b*x[j]+dp[j];}
inline ll sol(ll i,ll j,ll k){
    ll a1=-2*a*x[i],b1=a*x[i]*x[i]-b*x[i]+dp[i];
    ll a2=-2*a*x[j],b2=a*x[j]*x[j]-b*x[j]+dp[j];
    ll a3=-2*a*x[k],b3=a*x[k]*x[k]-b*x[k]+dp[k];
    return a3*(b1-b2)+a1*(b2-b3)>=a2*(b1-b3);
}
int main(){Rosario
    cin>>n>>a>>b>>c;
    REP1(i,1,n) cin>>x[i],x[i]+=x[i-1];
    v.em(0);
    REP1(i,1,n){
        while(v.size()>1&&ret(i,v[0])<=ret(i,v[1])) v.erase(v.begin());
        dp[i]=ret(i,v[0])+a*x[i]*x[i]+b*x[i]+c;
        while(v.size()>1&&sol(v[v.size()-2],v[v.size()-1],i)) v.pop_back();
        v.em(i);
    }cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
