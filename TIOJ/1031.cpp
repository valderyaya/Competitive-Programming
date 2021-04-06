//#pragma GCC optimize("Ofast")
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

ll n,sum;
ll power(ll a,ll n){
    ll ans=1;
    for(;n;n>>=1,a*=a){
        if(n&1) ans*=a;
    }
    return ans;
}
int main(){
    Rosario
    while(cin>>n,n){
        if(log2(n)==int(log2(n))) sum=n;
        else sum=power(2,log2(n));
        while(cin>>n,n){
            if(log2(n)==int(log2(n))) sum+=n;
            else sum+=power(2,log2(n));
        }
        cout<<sum<<"\n";
    }
//    system("pause");
    return 0;
}
