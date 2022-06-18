#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

ll power(ll a,ll n,ll mod){
    ll ans=1;
    for(;n;n>>=1,a=a*a%mod){
        if(n&1) ans=ans*a%mod;
    }
    return ans%mod;
}
int main(){
    //oi;
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<a<<'^'<<b<<" mod "<<c<<'='<<power(a,b,c)<<"\n";
//    system("pause");
    return 0;
}
